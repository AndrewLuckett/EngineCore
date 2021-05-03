#include "Texture.h"

#include "../stb_image/stb_image.h"

uint loadTexture(string path, int type) {
	int width, height, bpp;
	//stbi_set_flip_vertically_on_load(1);
	auto b = stbi_load(path.c_str(), &width, &height, &bpp, 4);

	uint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, type);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, type);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, b);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(b);
	return id;
}