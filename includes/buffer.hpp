#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "glessential.hpp"
#include "vertexbuffer.hpp"

class Buffer {
public:
    Buffer(unsigned int shaderID);
};

Buffer::Buffer(unsigned int shaderID) {
    Vertex vertices[4] = {
		{ -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f },
		{  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f },
		{ -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f },

		//{  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f },
		//{ -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f },
		{  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f }
	};

	unsigned int indices_array[6] = {
		0, 1, 2,
		1, 2, 3
	};

    // Create a Vertex Buffer Object and copy the vertex data to it
	GLuint ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices_array, GL_DYNAMIC_DRAW));

	VertexBuffer vertexBuffer(shaderID);
	vertexBuffer.refresh(vertices);

}

#endif //BUFFER_HPP