
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Texture::Texture(const char* path) {
	Texture::loadTexture(path);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Texture::~Texture() {
	glDeleteTextures(1, &this->textureID);
}


/*------------------------------------------------------------------------------
< loadTexture >
------------------------------------------------------------------------------*/
void Texture::loadTexture(const char* path) {
	glGenTextures(1, &this->textureID);

	unsigned char *data = stbi_load(path, &this->width, &this->height, &this->channel, 0);
	if (data) {
		GLenum format;
		if (this->channel == 1)
			format = GL_RED;
		else if (this->channel == 3)
			format = GL_RGB;
		else if (this->channel == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, this->textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, this->width, this->height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		stbi_image_free(data);
	}
	else {
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}
}
