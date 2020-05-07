#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader.hpp"
#include "buffer.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <vector>

void texture(Shader& shader, unsigned int slot, char const *filepath) {
	shader.setInt("texture0" + std::to_string(slot), slot);
	unsigned int tex_id;
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glGenTextures(1, &tex_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, tex_id));
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 4);
	if (data) {
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

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

	shader.use();

	texture(shader, 0, "assets/textures/behance.png");
	texture(shader, 1, "assets/textures/dribble.png");
	texture(shader, 2, "assets/textures/facebook.png");
	texture(shader, 3, "assets/textures/instagram.png");
	texture(shader, 4, "assets/textures/pinterest.png");
	texture(shader, 5, "assets/textures/snapchat.png");
	texture(shader, 6, "assets/textures/soundcloud.png");
	texture(shader, 7, "assets/textures/steam.png");
	texture(shader, 8, "assets/textures/stumbleupon.png");
	texture(shader, 9, "assets/textures/skype.png");
	
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
