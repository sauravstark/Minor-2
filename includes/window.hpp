#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>
#include "shader.hpp"

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_opengles2.h>

class Window {
private:
	SDL_Window* window;
	GLfloat vertices[36] = {
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,

		 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f
	};
public:
	Window();
	void update();
	void beginDraw();
	void draw();
	void endDraw();
};

Window::Window() {
	SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, nullptr);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Shader sources
	const GLchar* vertexSource =
		"attribute vec4 position;                     \n"
		"void main()                                  \n"
		"{                                            \n"
		"  gl_Position = vec4(position.xyz, 1.0);     \n"
		"}                                            \n";
	const GLchar* fragmentSource =
		"precision mediump float;\n"
		"void main()                                  \n"
		"{                                            \n"
		"  gl_FragColor[0] = gl_FragCoord.x/1920.0;\n"
		"  gl_FragColor[1] = gl_FragCoord.y/1080.0;\n"
		"  gl_FragColor[2] = 0.5;                     \n"
		"}                                            \n";


	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, vertices, GL_STATIC_DRAW);

	Shader shader("./shaders/vertex.shader", "./shaders/fragment.shader");
	shader.use();

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shader.getID(), "aPosition");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(0 * sizeof(float)));
	GLint colAttrib = glGetAttribLocation(shader.getID(), "aColor");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(2 * sizeof(float)));
	glClearColor(0.745f, 0.416f, 0.651f, 0.925f);
}

void Window::update() {
	const uint32_t milliseconds_since_start = SDL_GetTicks();
	const uint32_t milliseconds_per_loop = 3000;
	vertices[0] = (milliseconds_since_start % milliseconds_per_loop) / float(milliseconds_per_loop) - 0.5f;
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Window::beginDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::draw() {
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Window::endDraw() {
	SDL_GL_SwapWindow(window);
}

#endif // !WINDOW_HPP
