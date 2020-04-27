#ifndef VERTEX_HPP
#define VERTEX_HPP

#define MaxQuadCount    256
#define MaxVertexCount  MaxQuadCount * 4
#define MaxIndicesCount MaxQuadCount * 6

struct Vertex {
	float pos_x, pos_y, pos_z;
	float col_r, col_g, col_b, col_a;
};

#endif //!VERTEX_HPP