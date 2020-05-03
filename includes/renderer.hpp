#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader.hpp"
#include "buffer.hpp"
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
	shader(Shader("./shaders/vertex.shader", "./shaders/fragment.shader")) {
	shader.use();
	
	GLCall(glClearColor(1.0f, 1.0f, 1.0f, 1.0f));
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
