#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "glessential.hpp"
#include <vector>

class IndexBuffer {
public:
    GLuint id;
    IndexBuffer();
};

IndexBuffer::IndexBuffer() {
    GLCall(glGenBuffers(1, &id));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));

    GLuint indices_array[MaxIndicesCount];
    for (int i = 0; i < MaxQuadCount; ++i) {
        indices_array[i * 6 + 0] = i * 4 + 0;
        indices_array[i * 6 + 1] = i * 4 + 1;
        indices_array[i * 6 + 2] = i * 4 + 2;

        indices_array[i * 6 + 3] = i * 4 + 1;
        indices_array[i * 6 + 4] = i * 4 + 2;
        indices_array[i * 6 + 5] = i * 4 + 3;
    }

	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, MaxIndicesCount * sizeof(unsigned int), indices_array, GL_DYNAMIC_DRAW));
}

#endif //!INDEX_BUFFER_HPP