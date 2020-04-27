#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "glessential.hpp"
#include "vertex.hpp"

class VertexBuffer {
public:
    GLuint id;
    VertexBuffer(GLuint shaderID);
    void refresh(Vertex* ptr);
};

VertexBuffer::VertexBuffer(GLuint shaderID) {
    GLCall(glGenBuffers(1, &id));
    glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, nullptr, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderID, "aPosition");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0 * sizeof(float)));
	GLint colAttrib = glGetAttribLocation(shaderID, "aColor");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(9 * sizeof(float)));
}

void VertexBuffer::refresh(Vertex* ptr) {
    GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * sizeof(Vertex), ptr));
}

#endif //!VERTEX_BUFFER_HPP