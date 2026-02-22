#ifndef matrix_h
#define matrix_h
#include "vector.h"

namespace spencer {

class matrix {
private:
    double a11;
    double a12;
    double a21;
    double a22;

public:
// First constructor: takes two vectors as parameters
matrix(const vector& v1, const vector& v2);

// Default constructor: four default values forming identity matrix
matrix(double a11 = 1, double a12 = 0, double a21 = 0, double a22 = 1);

// Getters
double get_a11() const;
double get_a12() const;
double get_a21() const;
double get_a22() const;

// Setters
void set_a11(double val);
void set_a12(double val);
void set_a21(double val);
void set_a22(double val);

// Transpose
matrix transpose() const;

// Check if identity matrix
bool is_identity() const;

// Determinant
double determinant() const;

// Inverse
matrix inverse() const;

// Print
void print() const;
};

// Dot product: matrix * matrix
matrix dot(const matrix& m1, const matrix& m2);

// Dot product: matrix * column vector
vector dot(const matrix& m, const vector& v);

// Operator overloading: matrix + matrix
matrix operator+(const matrix& lhs, const matrix& rhs);
// Operator overloading: matrix - matrix
matrix operator-(const matrix& lhs, const matrix& rhs);
// Operator overloading: matrix * matrix
matrix operator*(const matrix& lhs, const matrix& rhs);

// Operator overloading: matrix + scalar
matrix operator+(const matrix& m, double k);
// Operatior overloading: scalar + matrix
matrix operator+(double k, const matrix& m);
// Operator overloading: matrix - scalar
matrix operator-(const matrix& m, double k);
// Operator overloading: scalar - matrix
matrix operator-(double k, const matrix& m);
// Operator overloading: matrix * scalar
matrix operator*(const matrix& m, double k);
// Operator overloading: scalar * matrix
matrix operator*(double k, const matrix& m);

}

#endif