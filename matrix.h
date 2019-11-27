#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include "vector3.h"
using namespace std;

enum Affine {ROTATEX,ROTATEY,ROTATEZ,SCALE,TRANSLATE,SHEAR};

class Matrix {
public:
	vector<vector<double> > mat;
	Matrix();
	Matrix(const Matrix& t);
	Matrix(Matrix& t);
	Matrix(Affine type, Vector3 v, Vector3 extra);
	Matrix(Affine type, double angle);
	Matrix(Affine type, Vector3 v);
	Matrix(double* V);

	void swapRows(int i, int j);
	void divideRow(int i, double temp);
	int getRow(int i);
	Vector3 transform(Vector3 point, int w) const;
	void subRow(int i, int j, double temp);
	Matrix operator * (const Matrix& v) const;
	void print();
	Matrix transpose();
	Matrix inverse();
};

#endif