#include "matrix.h"
#include <iostream>
#include <cassert>

namespace spencer {

// Constructor from two vectors
// Column vectors: each vector becomes a column
// Row vectors: each vector becomes a row
matrix::matrix(vector v1, vector v2) {
    if (v1.get_is_row() == false && v2.get_is_row() == false) {
        // Both column vectors: v1 is first column, v2 is second column
        a11 = v1.get_x1();
        a12 = v2.get_x1();
        a21 = v1.get_x2();
        a22 = v2.get_x2();
    } else if (v1.get_is_row() == true && v2.get_is_row() == true) {
        // Both row vectors: v1 is first row, v2 is second row
        a11 = v1.get_x1();
        a12 = v1.get_x2();
        a21 = v2.get_x1();
        a22 = v2.get_x2();

    } else {
        // Mixed: should not happen per assignment
        // Default to identity
        a11 = 1; a12 = 0; a21 = 0; a22 = 1;
    }
}

// Default constructor (identity matrix by defaults)
matrix::matrix(double a11, double a12, double a21, double a22) {
    a11 = a11;
    a12 = a12;
    a21 = a21;
    a22 = a22;
}

// Getters
double matrix::get_a11() { return a11; }
double matrix::get_a12() { return a12; }
double matrix::get_a21() { return a21; }
double matrix::get_a22() { return a22; }

// Transpose
matrix matrix::transpose() {
    return matrix(a11, a12, a21, a22);
}

// Check if identity matrix
bool matrix::is_identity() {
    return (a11 == 1 && a12 == 0 && a21 == 0 && a22 == 1);
}

// Determinant
double matrix::determinant() {  
    return (a11 * a22) - (a21 * a12);
}

// Inverse
matrix matrix::inverse() {
    double det = determinant();
    assert(det != 0);
    double inv_det = 1.0/det;
    return matrix(a22 * inv_det, -a12 * inv_det,
                  -a21 * inv_det, a11 * inv_det);
}

// Print
void matrix::print() {
    std::cout << "[" << a11 << " " << a12 << std::endl;
    std::cout << " " << a21 << " " << a22 << "]" << std::endl;
}

// Dot product: matrix * matrix
matrix dot(matrix m1, matrix m2) {
    return matrix(
        m1.get_a11() * m2.get_a11() + m1.get_a12() * m2.get_a21(),
        m1.get_a11() * m2.get_a12() + m1.get_a12() * m2.get_a22(),
        m1.get_a21() * m2.get_a11() + m1.get_a22() * m2.get_a21(),
        m1.get_a21() * m2.get_a12() + m1.get_a22() * m2.get_a22()
    );
}

// Dot product: matrix * column vector
vector dot(matrix m, vector v) {
    return vector(
        m.get_a11() * v.get_x1() + m.get_a12() * v.get_x2(),
        m.get_a21() * v.get_x1() + m.get_a22() * v.get_x2(),
        false    // result is a column vector
    );
}


// matrix + matrix
matrix operator+(matrix lhs, matrix rhs) {
    return matrix(lhs.get_a11() + rhs.get_a11(),
                  lhs.get_a12() + rhs.get_a12(),
                  lhs.get_a21() + rhs.get_a21(),
                  lhs.get_a22() + rhs.get_a22());
}

// matrix - matrix
matrix operator-(matrix lhs, matrix rhs) {
    return matrix(lhs.get_a11() - rhs.get_a11(),
                  lhs.get_a12() - rhs.get_a12(),
                  lhs.get_a21() - rhs.get_a21(),
                  lhs.get_a22() - rhs.get_a22());
}
// matrix * matrix
matrix operator*(matrix lhs, matrix rhs) {
    return matrix(lhs.get_a11() * rhs.get_a11(),
                  lhs.get_a12() * rhs.get_a12(),
                  lhs.get_a21() * rhs.get_a21(),
                  lhs.get_a22() * rhs.get_a22());
}

// matrix + scalar
matrix operator+(matrix m, double k) {
    return matrix(m.get_a11() + k, m.get_a12() + k,
                  m.get_a21() + k, m.get_a22() + k);
}

// scalar + matrix
matrix operator+(double k, matrix m) {
    return m + k;
}

// matrix - scalar
matrix operator-(matrix m, double k) {
    return matrix(m.get_a11() - k, m.get_a12() - k,
                  m.get_a21() - k, m.get_a22() - k);
}

// scalar - matrix
matrix operator-(double k, matrix m) {
    return matrix(k - m.get_a11(), k - m.get_a12(),
                  k - m.get_a21(), k - m.get_a22());
}

// matrix * scalar
matrix operator*(matrix m, double k) {
    return matrix(m.get_a11() * k, m.get_a12() * k,
                  m.get_a21() * k, m.get_a22() * k);
}

// scalar * matrix
matrix operator*(double k, matrix m) {
    return m * k;
}

}
