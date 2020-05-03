#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glessential.hpp"

#include<iostream>
#include<string>

stbi_set_flip_vertically_on_load(true);

class Texture
{
private:
	GLuint id;
	int width;
	int height;
    int channels;
	unsigned int type;

public:

	Texture(const char* fileName, GLenum type)
	{
		this->type = type;

		unsigned char *image = stbi_load(fileName, &this->width, &this->height, &this->nrChannels, 0);

		GLCall(glGenTextures(1, &this->id));
		GLCall(glBindTexture(type, this->id));

		GLCall(glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR));
		GLCall(glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR));

		if (image)
		{
			GLCall(glTexImage2D(type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image));
			GLCall(glGenerateMipmap(type));
		}
		else
		{
			std::cout << "ERROR::TEXTURE::TEXTURE_LOADING_FAILED: " << fileName <<"\n";
		}

		GLCall(glActiveTexture(0));
		GLCall(glBindTexture(type, 0));
        stbi_image_free(image);
	}

	~Texture()
	{
		GLCall(glDeleteTextures(1, &this->id));
	}

	inline GLuint getID() const { return this->id; }

	void bind(const GLint texture_unit)
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + texture_unit));
		GLCall(glBindTexture(this->type, this->id));
	}

	void unbind()
	{
		GLCall(glActiveTexture(0));
		GLCall(glBindTexture(this->type, 0));
	}

	void loadFromFile(const char* fileName)
	{
		if (this->id)
		{
			GLCall(glDeleteTextures(1, &this->id));
		}

		unsigned char *image = stbi_load(fileName, &this->width, &this->height, &this->nrChannels, 0);

		GLCall(glGenTextures(1, &this->id));
		GLCall(glBindTexture(this->type, this->id));

		GLCall(glTexParameteri(this->type, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(this->type, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR));
		GLCall(glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_LINEAR));

		if (image)
		{
			GLCall(glTexImage2D(this->type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image));
			GLCall(glGenerateMipmap(this->type));
		}
		else
		{
			std::cout << "ERROR::TEXTURE::LOADFROMFILE::TEXTURE_LOADING_FAILED: " << fileName << "\n";
		}

		GLCall(glActiveTexture(0));
		GLCall(glBindTexture(this->type, 0));
		stbi_image_free(image);
	}
};

#endif // !TEXTURE_HPP