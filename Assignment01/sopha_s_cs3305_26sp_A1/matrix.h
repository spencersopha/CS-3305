#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

namespace spencer {

class matrix {
private:
    double a11, a12, a21, a22;

public:
// First constructor: takes two vectors as parameters
matrix(vector v1, vector v2);

// Default constructor: four default values forming identity matrix
matrix(double a11 = 1, double a12 = 0, double a21 = 0, double a22 = 1);

// Getters
double get_a11();
double get_a12();
double get_a21();
double get_a22();

// Setters
void set_a11(double val);
void set_a12(double val);
void set_a21(double val);
void set_a22(double val);

// Transpose
matrix transpose();

// Check if identity matrix
bool is_identity();

// Determinant
double determinant();

// Inverse
matrix inverse();

// Print
void print();
};

// Dot product: matrix * matrix
matrix dot(matrix m1, matrix m2);

// Dot product: matrix * column vector
vector dot(matrix m, vector v);

// Operator overloading: matrix + matrix
matrix operator+(matrix lhs, matrix rhs);
// Operator overloading: matrix - matrix
matrix operator-(matrix lhs, matrix rhs);
// Operator overloading: matrix * matrix
matrix operator*(matrix lhs, matrix rhs);

// Operator overloading: matrix + scalar
matrix operator+(matrix m, double k);
// Operatior overloading: scalar + matrix
matrix operator+(double k, matrix m);
// Operator overloading: matrix - scalar
matrix operator-(matrix m, double k);
// Operator overloading: scalar - matrix
matrix operator-(double k, matrix m);
// Operator overloading: matrix * scalar
matrix operator*(matrix m, double k);
// Operator overloading: scalar * matrix
matrix operator*(double k, matrix m);

}

#endif
