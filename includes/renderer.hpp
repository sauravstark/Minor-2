#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader.hpp"
#include "buffer.hpp"

class Renderer {
private:
	Shader shader;
	Buffer buffer;
public:
	Renderer();
	void update();
	void draw();
};

Renderer::Renderer() :
	shader(Shader("./shaders/vertex.shader", "./shaders/fragment.shader")) {
	shader.use();

	Vertex vertices[16] = {
		{ -0.75f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
		{ -0.25f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
		{ -0.75f, -0.25f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
		{ -0.25f, -0.25f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },

		{  0.75f, -0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
		{  0.25f, -0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
		{  0.75f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
		{  0.25f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
		
		{ -0.75f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
		{ -0.25f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
		{ -0.75f,  0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
		{ -0.25f,  0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },

		{  0.75f,  0.75f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f },
		{  0.25f,  0.75f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f },
		{  0.75f,  0.25f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f },
		{  0.25f,  0.25f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f }
		
	};

	buffer.refresh(vertices);
	
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Renderer::update() {
	/*
	const uint32_t milliseconds_since_start = SDL_GetTicks();
	const uint32_t milliseconds_per_loop = 3000;
	vertices[0] = (milliseconds_since_start % milliseconds_per_loop) / float(milliseconds_per_loop) - 0.5f;
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	*/
}

void Renderer::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	GLCall(glDrawElements(GL_TRIANGLES, 24,  GL_UNSIGNED_INT, nullptr));
}

#endif //!RENDERER_HPP
