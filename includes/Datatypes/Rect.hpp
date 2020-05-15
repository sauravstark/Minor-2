#ifndef RECT_HPP
#define RECT_HPP

#include "./Vec.hpp"

struct Rect {
	vec<2> centre, span;
	float angle;

	Rect(vec<2> pos = vec<2>(0.0f, 0.0f), vec<2> size = vec<2>(1.0f, 1.0f), float rot = 0.0f);

	bool contains(vec<2>& P) const;
	bool contains(const Rect& other) const;
	bool overlaps(const Rect& other) const;
};

inline Rect::Rect(vec<2> pos, vec<2> size, float rot) :
	centre(pos), span(size), angle(rot) {}

inline bool Rect::contains(vec<2>& P) const {
	float x = centre.get(0), y = centre.get(1);
	float l = span.get(0) / 2, b = span.get(1) / 2;
	float rot = angle;
	vec<2> A = { x + (-l) * cosf(rot) + (-b) * (-sinf(rot)), y + (-l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> B = { x + ( l) * cosf(rot) + (-b) * (-sinf(rot)), y + ( l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> C = { x + ( l) * cosf(rot) + ( b) * (-sinf(rot)), y + ( l) * sinf(rot) + ( b) * cosf(rot) };
	vec<2> D = { x + (-l) * cosf(rot) + ( b) * (-sinf(rot)), y + (-l) * sinf(rot) + ( b) * cosf(rot) };
	bool ret = true;
	ret = ret && ((B[0] - A[0]) * (P[1] - A[1]) - (B[1] - A[1]) * (P[0] - A[0]) > 0);
	ret = ret && ((C[0] - B[0]) * (P[1] - B[1]) - (C[1] - B[1]) * (P[0] - B[0]) > 0);
	ret = ret && ((D[0] - C[0]) * (P[1] - C[1]) - (D[1] - C[1]) * (P[0] - C[0]) > 0);
	ret = ret && ((A[0] - D[0]) * (P[1] - D[1]) - (A[1] - D[1]) * (P[0] - D[0]) > 0);
	return ret;
}

inline bool Rect::contains(const Rect& other) const {
	float x = other.centre.get(0), y = other.centre.get(1);
	float l = other.span.get(0) / 2, b = other.span.get(1) / 2;
	float rot = other.angle;
	vec<2> A = { x + (-l) * cosf(rot) + (-b) * (-sinf(rot)), y + (-l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> B = { x + ( l) * cosf(rot) + (-b) * (-sinf(rot)), y + ( l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> C = { x + ( l) * cosf(rot) + ( b) * (-sinf(rot)), y + ( l) * sinf(rot) + ( b) * cosf(rot) };
	vec<2> D = { x + (-l) * cosf(rot) + ( b) * (-sinf(rot)), y + (-l) * sinf(rot) + ( b) * cosf(rot) };
	return contains(A) && contains(B) && contains(C) && contains(D);
}

inline bool Rect::overlaps(const Rect& other) const {
	float x = other.centre.get(0), y = other.centre.get(1);
	float l = other.span.get(0) / 2, b = other.span.get(1) / 2;
	float rot = other.angle;
	vec<2> A = { x + (-l) * cosf(rot) + (-b) * (-sinf(rot)), y + (-l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> B = { x + ( l) * cosf(rot) + (-b) * (-sinf(rot)), y + ( l) * sinf(rot) + (-b) * cosf(rot) };
	vec<2> C = { x + ( l) * cosf(rot) + ( b) * (-sinf(rot)), y + ( l) * sinf(rot) + ( b) * cosf(rot) };
	vec<2> D = { x + (-l) * cosf(rot) + ( b) * (-sinf(rot)), y + (-l) * sinf(rot) + ( b) * cosf(rot) };
	return contains(A) || contains(B) || contains(C) || contains(D) || other.contains(*this);
}

#endif // !RECT_HPP
