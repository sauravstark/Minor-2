#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "glessential.hpp"
#include <vector>

class IndexBuffer {
public:
    GLuint id;
    IndexBuffer();
    void bind();
};



#endif //!INDEX_BUFFER_HPP