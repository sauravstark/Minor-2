#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "glessential.hpp"
#include "vertexbuffer.hpp"
#include "indexbuffer.hpp"

class Buffer {
private:
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;

public:
    Buffer(unsigned int shaderID);
	void refresh(Vertex *ptr);
};

Buffer::Buffer(unsigned int shaderID) : vertexBuffer(VertexBuffer(shaderID)){}

void Buffer::refresh(Vertex *ptr) {
	vertexBuffer.refresh(ptr);
}

#endif //BUFFER_HPP