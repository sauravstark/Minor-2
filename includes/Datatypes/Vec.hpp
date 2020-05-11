#ifndef VEC_HPP
#define VEC_HPP

#include <cassert>

template<unsigned int dim>
class vec {
private:
	float vals[dim] = { 0.0f };
public:
	vec();
	vec(float x1);
	vec(float x1, float x2);
	vec(float x1, float x2, float x3);
	vec(float x1, float x2, float x3, float x4);
	float& operator[](unsigned int index);
};

template<unsigned int dim>
vec<dim>::vec() {
	assert((dim > 0) && (dim < 5));
	for (unsigned int i = 0; i < dim; ++i)
		vals[i] = 0.0f;
}

template<unsigned int dim>
vec<dim>::vec(float x1) {
	assert(dim == 1);
	vals[0] = x1;
}

template<unsigned int dim>
vec<dim>::vec(float x1, float x2) {
	assert(dim == 2);
	vals[0] = x1;
	vals[1] = x2;
}

template<unsigned int dim>
vec<dim>::vec(float x1, float x2, float x3) {
	assert(dim == 3);
	vals[0] = x1;
	vals[1] = x2;
	vals[2] = x3;
}

template<unsigned int dim>
vec<dim>::vec(float x1, float x2, float x3, float x4) {
	assert(dim == 4);
	vals[0] = x1;
	vals[1] = x2;
	vals[2] = x3;
	vals[3] = x4;
}

template<unsigned int dim>
float& vec<dim>::operator[](unsigned int index) {
	return vals[index];
}

#endif //!VEC_HPP