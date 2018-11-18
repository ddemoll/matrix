#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdlib.h>
using namespace std;
template<typename T>
matrix<T> matrix<T>::t() const {
	matrix<T> m{ numcols(), numrows() };
	for (int i = 0; i < numrows(); i++)
		for (int j = 0; j < numcols(); j++)
			m[j][i] = arr[i][j];
	return m;
}
template <typename T>
const matrix<T> & matrix<T>::operator=(const matrix<T> & rhs) {
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	if (this != &rhs) {
		arr = rhs.arr;
	}
	return *this;
}
template<typename T>
const matrix<T> matrix<T>::operator+=(const matrix<T> & rhs) {
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	for (int i = 0; i < numrows(); i++)
		for (int j = 0; j < numcols(); j++)
			arr[i][j] += rhs.arr[i][j];
	return *this;
}
template<typename T>
const matrix<T> matrix<T>::operator+ (const matrix<T> & rhs) const {
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	return matrix<T>{ *this } += rhs;
}
template<typename T>
const matrix<T> matrix<T>::operator*= (const T &c) {
	for (int i = 0; i < numrows(); i++)
		for (int j = 0; j < numcols(); j++)
			arr[i][j] *= c;
	return *this;
}
template<typename T>
const matrix<T> matrix<T>::operator* (const T &c) const {
	return matrix<T>{ *this } *= c;
}
template<typename T>
const matrix<T> matrix<T>::operator* (const matrix<T> & rhs)const {
	assert(this->numcols() == rhs.numrows());
	matrix<T> m{ numrows(), rhs.numcols() };

	for (int i{}; i < numrows(); i++) {
		for (int j{}; j < rhs.numcols(); j++) {
			m[i][j] = T{};
			for (int k{}; k < rhs.numrows(); k++) {
				m[i][j] += arr[i][k] * rhs.arr[k][j];
			}
		}
	}

	return m;
}
template<typename T>
vector<T> matrix<T>::row(int k) const {
	//check if index is within bounds
	assert(k < numrows());
	return arr[k];
}
template<typename T>
vector<T> matrix<T>::col(int k) const {
	assert(k < numcols());
	vector<T> v;
	for (int i{}; i < numrows(); i++)
		v.push_back(arr[i][k]);
	return v;
}
template<typename T>
matrix<T> matrix<T>::deleteRow(int k) const {
	matrix<T> m{*this};
	m.arr.erase(m.arr.begin() + k);
	return m;
}
template<typename T>
matrix<T> matrix<T>::deleteCol(int k) const {
	matrix<T> m{ *this };
	for (int i{}; i < numrows(); i++)
		m.arr[i].erase(m.arr[i].begin() + k);
	return m;
}
template <typename T>
T matrix<T>::det_aux() {
	T sum;
	if (this->numrows() == 0)
		return 0;
	else if (this->numrows() == 1)
		return this->arr[0][0];
	else if (this->numrows() == 2)
		return this->arr[0][0] * this->arr[1][1] - this->arr[1][0] * this->arr[0][1];
	else {
		sum = T();
		for (int k = 0; k < this->numcols(); k++)
			sum += (k % 2 == 0 ? 1 : -1)*deleteRow(0).deleteCol(k).det_aux()*arr[0][k];
	}
	return sum;
}
template <typename T>
T matrix<T>::det() {
	assert(this->numrows() == this->numcols());
	return this->det_aux();
}
template<typename T>
void matrix<T>::read(istream & in = cin) {
	int totalElements = numrows()*numcols();
	for (int i = 0; i < numrows(); i++)
		for (int j = 0; j < numcols(); j++)
			this->arr[i][j] = T();
	if (this->numrows() == 0) return;
	int numberOfElements = 0;
	while (numberOfElements < totalElements && in >> ws && !in.eof()) {
		T element;
		numberOfElements++;
		in >> element;
		this->arr[(numberOfElements - 1) / numcols()][(numberOfElements - 1) % numcols()] = element;
	}
}
template<typename T>
void matrix<T>::print(ostream & out = cout) const {
	for (int i = 0; i < numrows(); i++) {
		cout << this->arr[i][0];
		for (int j = 1; j < numcols(); j++)
			cout << " " << this->arr[i][j];
		cout << endl;
	}
}
template<typename T>
istream& operator >> (istream & in, matrix<T> & rhs) {
	rhs.read(in);
	return in;
}
template<typename T>
ostream& operator<<(ostream & out, const matrix<T> & rhs) {
	rhs.print(out);
	return out;
}
template<typename T>
T dot(const vector<T> & lvec, const vector<T> & rvec) {
	T sum{};
	for (int i{}; i < lvec.size(); ++i)
		sum += lvec[i] * rvec[i];
	return sum;
}
template<typename T>
matrix<T> eye(int n) {
	matrix<T> m{ n,n };
	for (int i{}; i < n; i++)
		for (int j{}; j < n; j++)
			m[i][j] = i == j ? 1 : 0;
	return m;
}
template<typename T>
matrix<T> zeroes(int rows, int cols) {
	matrix<T> zeroesMat{ rows, cols };
	for (int i{}; i < rows; i++)
		for (int j{}; j < cols; j++)
			zeroesMat[i][j] = 0;
	return zeroesMat;
}
template<typename T>
matrix<T> ones(int rows, int cols) {
	matrix<T> onesMat{ rows, cols };
	for (int i{}; i < rows; i++)
		for (int j{}; j < cols; j++)
			onesMat[i][j] = 1;
	return onesMat;
}
#endif