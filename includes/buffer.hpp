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
	void refresh(Vertex *ptr);
};

void Buffer::refresh(Vertex *ptr) {
	vertexBuffer.refresh(ptr);
}

#endif //BUFFER_HPP