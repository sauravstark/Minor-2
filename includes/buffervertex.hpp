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
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * MaxVertexCount, nullptr, GL_STATIC_DRAW));

	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0 * sizeof(float))));
    GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float))));
    GLCall(glEnableVertexAttribArray(1));
    GLCall(glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(7 * sizeof(float))));
    GLCall(glEnableVertexAttribArray(2));
}

void VertexBuffer::refresh(Vertex* ptr) {
    GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, MaxVertexCount * sizeof(Vertex), ptr));
}

#endif //!BUFFER_VERTEX_HPP