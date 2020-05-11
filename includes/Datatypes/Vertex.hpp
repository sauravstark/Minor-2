#ifndef VERTEX_HPP
#define VERTEX_HPP

#define MaxQuadCount    1024 * 16
#define MaxVertexCount  MaxQuadCount * 4
#define MaxIndicesCount MaxQuadCount * 6

#include "./Vec.hpp"

struct Vertex {
	vec<3> pos;
	vec<4> col;
	vec<3> tex;
};

#endif //!VERTEX_HPP