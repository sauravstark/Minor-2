#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader.hpp"
#include "buffer.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <vector>

class Renderer {
private:
	Shader shader;
	Buffer buffer;
public:
	Renderer();
	void update();
	void draw(std::vector<Vertex> &vertices);
};

Renderer::Renderer() :
	shader(Shader("./assets/shaders/vertex.glsl", "./assets/shaders/fragment.glsl")) {
	
	//shader.setInt("texture1", 1);
	shader.use();
	for (unsigned int i = 0; i < 16; ++i) {
		std::string slot = std::to_string(i);
		std::string utex = std::string("texture") + std::string(2 - slot.length(), '0') + slot;
		shader.setInt(utex, i);
	}

	

	unsigned int texture1;
	GLCall(glGenTextures(1, &texture1));
    GLCall(glBindTexture(GL_TEXTURE_2D, texture1));
	int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("assets/textures/facebook.png", &width, &height, &nrChannels, 4);
    if (data)
    {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
	GLCall(glActiveTexture(GL_TEXTURE1));
	GLCall(glGenTextures(1, &texture1));
    GLCall(glBindTexture(GL_TEXTURE_2D, texture1));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	data = stbi_load("assets/textures/instagram.png", &width, &height, &nrChannels, 4);
    if (data)
    {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
	GLCall(glActiveTexture(GL_TEXTURE2));
	GLCall(glGenTextures(1, &texture1));
    GLCall(glBindTexture(GL_TEXTURE_2D, texture1));
	data = stbi_load("assets/textures/dribble.png", &width, &height, &nrChannels, 4);
    if (data)
    {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
	
	GLCall(glClearColor(0.0f, 0.0f, 1.0f, 1.0f));
}

void Renderer::update() {
}

void Renderer::draw(std::vector<Vertex> &vertices) {
	unsigned int quad_count = vertices.size() / 4;
	Vertex *ptr = vertices.data();

	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	while (quad_count > MaxQuadCount) {
		buffer.refresh(ptr);
		GLCall(glDrawElements(GL_TRIANGLES, MaxIndicesCount,  GL_UNSIGNED_INT, nullptr));

		ptr += MaxVertexCount;
		quad_count -= MaxQuadCount;
	}
	
	buffer.refresh(ptr);
	GLCall(glDrawElements(GL_TRIANGLES, quad_count * 6,  GL_UNSIGNED_INT, nullptr));
}

#endif //!RENDERER_HPP
