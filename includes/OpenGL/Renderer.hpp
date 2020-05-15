#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "./Shader.hpp"
#include "./Buffer.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../External Libraries/stb_image.h"
#include <vector>

void texture(Shader& shader, unsigned int slot, char const *filepath) {
	std::string slot_str = std::to_string(slot);
	std::string texture_name = "texture" + std::string(2 - slot_str.length(), '0') + slot_str;
	shader.setInt(texture_name, slot);
	unsigned int tex_id;
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glGenTextures(1, &tex_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, tex_id));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
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

	texture(shader, 0, "assets/textures/characters.png");
	texture(shader, 1, "assets/textures/tiles.png");
	texture(shader, 2, "assets/textures/background.png");
	
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
