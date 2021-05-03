#include "ra.h"
#ifdef _DEBUG
    #include <iostream>
#endif
#include <fstream>

#include "ShaderGen.h"

string ParseFile(const string &filepath) {
	std::ifstream filestream(filepath);

	string text;
	text.assign((std::istreambuf_iterator<char>(filestream)), (std::istreambuf_iterator<char>()));
	return text;
}

uint CompileShader(uint type, const string &source) {
	uint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr); //Null terminated is assumed from nullptr
	glCompileShader(id);

	//std::cout << src << std::endl;

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result = GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
#ifdef _DEBUG
		std::cout << "Failed to compile :" << type << std::endl;
		std::cout << message << std::endl;
#endif
		glDeleteShader(id);
	}
	return id;
}

uint GenerateProgram(const string& vertex, const string& fragment) {
	string vesh = ParseFile(vertex);
	string frsh = ParseFile(fragment);

	uint programID = glCreateProgram();

	uint vs = CompileShader(GL_VERTEX_SHADER, vesh);
	uint fs = CompileShader(GL_FRAGMENT_SHADER, frsh);

	glAttachShader(programID, vs);
	glAttachShader(programID, fs);

	glLinkProgram(programID);
	return programID;
}
