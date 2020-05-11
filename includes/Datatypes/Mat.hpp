#ifndef MAT_HPP
#define MAT_HPP

#include <cassert>
#include "./Vec.hpp"

template<unsigned int dim>
class mat {
private:
	vec<dim> vals[dim];
public:
	mat();
	mat(float x1);
	mat(vec<dim> v1);
	mat(vec<dim> v1, vec<dim> v2);
	mat(vec<dim> v1, vec<dim> v2, vec<dim> v3);
	mat(vec<dim> v1, vec<dim> v2, vec<dim> v3, vec<dim> v4);
	vec<dim>& operator[](unsigned int index);
	mat<dim> operator*(const mat<dim> r_val);
	vec<dim> operator*(const vec<dim> r_val);
};

template<unsigned int dim>
mat<dim>::mat() {
	assert((dim > 0) && (dim < 5));
	for (unsigned int i = 0; i < dim; ++i)
		vals[i][i] = 1.0f;
}

template<unsigned int dim>
mat<dim>::mat(float x1) {
	assert((dim > 0) && (dim < 5));
	for (unsigned int i = 0; i < dim; ++i)
		vals[i][i] = x1;
}

template<unsigned int dim>
mat<dim>::mat(vec<dim> v1) {
    assert(dim == 1);
	vals[0] = v1;
}

template<unsigned int dim>
mat<dim>::mat(vec<dim> v1, vec<dim> v2) {
    assert(dim == 2);
	vals[0] = v1;
	vals[1] = v2;
}

template<unsigned int dim>
mat<dim>::mat(vec<dim> v1, vec<dim> v2, vec<dim> v3) {
    assert(dim == 3);
	vals[0] = v1;
	vals[1] = v2;
	vals[2] = v3;
}

template<unsigned int dim>
mat<dim>::mat(vec<dim> v1, vec<dim> v2, vec<dim> v3, vec<dim> v4) {
    assert(dim == 4);
	vals[0] = v1;
	vals[1] = v2;
	vals[2] = v3;
	vals[3] = v4;
}

template<unsigned int dim>
vec<dim>& mat<dim>::operator[](unsigned int index) {
	return vals[index];
}

template<unsigned int dim>
mat<dim> mat<dim>::operator*(const mat<dim> arg)
{
    mat<dim> l_val = *this, r_val = arg;
	mat<dim> ret;

	for (unsigned int row = 0; row < dim; ++row) {
		for (unsigned int col = 0; col < dim; ++col) {
			float x = 0.0f;
			for (unsigned int i = 0; i < dim; ++i) {
				x += l_val[row][i] * r_val[i][col];
			}
			ret[row][col] = x;
		}
	}

	return ret;
}

template<unsigned int dim>
vec<dim> mat<dim>::operator*(vec<dim> arg)
{
    mat<dim> l_mat = *this;
    vec<dim> r_vec = arg;
	vec<dim> ret;

	for (unsigned int row = 0; row < dim; ++row) {
		for (unsigned int col = 0; col < dim; ++col) {
			ret[row] += l_mat[row][col] * r_vec[col];
		}
	}

	return ret;
}

#endif