#ifndef VEC_HPP
#define VEC_HPP

#define PI 3.1415927f

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
	vec<dim> operator+(const vec<dim> r_val);
	vec<dim> operator-(const vec<dim> r_val);
	vec<dim> operator*(const vec<dim> r_val);
	vec<dim> operator*(const float r_val);
	float get(unsigned int index) const;
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

template<unsigned int dim>
vec<dim> vec<dim>::operator+(const vec<dim> arg)
{
	vec<dim> l_val = *this, r_val = arg;
	vec<dim> ret;

	for (unsigned i = 0; i < dim; ++i) {
		ret[i] = l_val[i] + r_val[i];
	}

	return ret;
}

template<unsigned int dim>
vec<dim> vec<dim>::operator-(const vec<dim> arg)
{
	vec<dim> l_val = *this, r_val = arg;
	vec<dim> ret;

	for (unsigned i = 0; i < dim; ++i) {
		ret[i] = l_val[i] - r_val[i];
	}

	return ret;
}

template<unsigned int dim>
vec<dim> vec<dim>::operator*(const vec<dim> arg)
{
	vec<dim> l_val = *this, r_val = arg;
	vec<dim> ret;

	for (unsigned i = 0; i < dim; ++i) {
		ret[i] = l_val[i] * r_val[i];
	}

	return ret;
}

template<unsigned int dim>
vec<dim> vec<dim>::operator*(const float arg)
{
	vec<dim> ret;

	for (unsigned i = 0; i < dim; ++i) {
		ret[i] = vals[i] * arg;
	}

	return ret;
}

template<unsigned int dim>
inline float vec<dim>::get(unsigned int index) const
{
	return vals[index];
}

#endif //!VEC_HPP