#ifndef VERTEX_HPP
#define VERTEX_HPP

#define MaxQuadCount    5
#define MaxVertexCount  MaxQuadCount * 4
#define MaxIndicesCount MaxQuadCount * 6

#include "vec.hpp"

struct Vertex {
	vec<3> pos;
	vec<4> col;
};

#endif //!VERTEX_HPP