#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_opengles2.h>

class Game {
private:
	GLfloat vertices[12] = { -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f };
	SDL_Window* window;
public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
};

Game::Game() {
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

	SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, nullptr);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertices, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

void Game::Update() {
	const uint32_t milliseconds_since_start = SDL_GetTicks();
	const uint32_t milliseconds_per_loop = 3000;
	vertices[0] = (milliseconds_since_start % milliseconds_per_loop) / float(milliseconds_per_loop) - 0.5f;
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Game::LateUpdate() { }

void Game::Draw() {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw a triangle from the 3 vertices
	glDrawArrays(GL_TRIANGLES, 0, 6);

	SDL_GL_SwapWindow(window);
}

#endif // !GAME_HPP
