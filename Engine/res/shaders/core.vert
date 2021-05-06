#version 400 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 coords;

uniform mat3 trans;
uniform mat3 camera;

out vec2 texCo;

void main() {
    gl_Position = vec4(camera * trans * vec3(position,1),1);
	texCo = coords;
};
