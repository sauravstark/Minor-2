#ifndef BUFFER_VERTEX_HPP
#define BUFFER_VERTEX_HPP

#include "glessential.hpp"
#include "vertex.hpp"

class VertexBuffer {
public:
    GLuint id;
    VertexBuffer();
    void refresh(Vertex* ptr);
};

VertexBuffer::VertexBuffer() {
    GLCall(glGenBuffers(1, &id));
    glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * MaxVertexCount, nullptr, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
	//GLint posAttrib = glGetAttribLocation(shaderID, "aPosition");
	//glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);
	//GLint colAttrib = glGetAttribLocation(shaderID, "aColor");
	//glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void VertexBuffer::refresh(Vertex* ptr) {
    GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, MaxVertexCount * sizeof(Vertex), ptr));
}

#endif //!BUFFER_VERTEX_HPP