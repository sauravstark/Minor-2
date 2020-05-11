#ifndef GLESSENTIAL_HPP
#define GLESSENTIAL_HPP

#define GL_GLEXT_PROTOTYPES 1
#include <GL/glfw.h>

#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	GLLogCall(#x, __FILE__, __LINE__);

static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line) {
	GLenum error = glGetError();

	if (error == GL_NO_ERROR)
		return false;
	do {
		std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
		error = glGetError();
	} while (error != GL_NO_ERROR);

	return true;
}

#endif //!GLESSENTIAL_HPP