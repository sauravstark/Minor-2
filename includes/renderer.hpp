#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include "shader.hpp"
#include "buffer.hpp"

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_opengles2.h>

class Renderer {
private:
	SDL_Window* window;
public:
	Renderer();
	void update();
	void draw();
};

Renderer::Renderer() {
	SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, nullptr);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	std::cout << glGetString(GL_VERSION) << std::endl;

	Shader shader("./shaders/vertex.shader", "./shaders/fragment.shader");
	shader.use();
	Buffer buffer;

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
	
	//glClearColor(0.745f, 0.416f, 0.651f, 0.925f);
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
	SDL_GL_SwapWindow(window);
}

#endif //!RENDERER_HPP
