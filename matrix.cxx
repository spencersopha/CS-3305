#include "matrix.h"
#include <iostream>
#include <cassert>

namespace spencer {

// Constructor from two vectors
// Column vectors: each vector becomes a column
// Row vectors: each vector becomes a row
matrix::matrix(const vector& v1, const vector& v2) {
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
        a11 = 1; a12 = 0;
        a21 = 0; a22 = 1;
    }
}

// Default constructor (identity matrix by defaults)
matrix::matrix(double a11, double a12, double a21, double a22)
    : a11(a11), a12(a12), a21(a21), a22(a22) {}

// Getters
double matrix::get_a11() const { return a11; }
double matrix::get_a12() const { return a12; }
double matrix::get_a21() const { return a21; }
double matrix::get_a22() const { return a22; }

// Transpose
matrix matrix::transpose() const {
    return matrix(a11, a12, a21, a22);
}

// Check if identity matrix
bool matrix::is_identity() const {
    return (a11 == 1 && a12 == 0 && a21 == 0 && a22 == 1);
}

// Determinant
double matrix::determinant() const {
    return (a11 * a22) - (a21 * a12);
}

// Inverse
matrix matrix::inverse() const {
    double det = determinant();
    assert(det != 0);
    double inv_det = 1.0/det;
    return matrix(a22 * inv_det, -a12 * inv_det,
                  -a21 * inv_det, a11 * inv_det);
}

// Print
void matrix::print() const {
    std::cout << "[" << a11 << " " << a12 << std::endl;
    std::cout << " " << a21 << " " << a22 << "]" << std::endl;
}

// Dot product: matrix * matrix
matrix dot(const matrix& m1, const matrix& m2) {
    return matrix(
        m1.get_a11() * m2.get_a11() + m1.get_a12() * m2.get_a21(),
        m1.get_a11() * m2.get_a12() + m1.get_a12() * m2.get_a22(),
        m1.get_a21() * m2.get_a11() + m1.get_a22() * m2.get_a21(),
        m1.get_a21() * m2.get_a12() + m1.get_a22() * m2.get_a22()
    );
}

// Dot product: matrix * column vector
vector dot(const matrix& m, const vector& v) {
    return vector(
        m.get_a11() * v.get_x1() + m.get_a12() * v.get_x2(),
        m.get_a21() * v.get_x1() + m.get_a22() * v.get_x2(),
        false    // result is a column vector
    );
}


// matrix + matrix
matrix operator+(const matrix& lhs, const matrix& rhs) {
    return matrix(lhs.get_a11() + rhs.get_a11(),
                  lhs.get_a12() + rhs.get_a12(),
                  lhs.get_a21() + rhs.get_a21(),
                  lhs.get_a22() + rhs.get_a22());
}

// matrix - matrix
matrix operator-(const matrix& lhs, const matrix& rhs) {
    return matrix(lhs.get_a11() - rhs.get_a11(),
                  lhs.get_a12() - rhs.get_a12(),
                  lhs.get_a21() - rhs.get_a21(),
                  lhs.get_a22() - rhs.get_a22());
}
// matrix * matrix
matrix operator*(const matrix& lhs, const matrix& rhs) {
    return matrix(lhs.get_a11() * rhs.get_a11(),
                  lhs.get_a12() * rhs.get_a12(),
                  lhs.get_a21() * rhs.get_a21(),
                  lhs.get_a22() * rhs.get_a22());
}

// matrix + scalar
matrix operator+(const matrix& m, double k) {
    return matrix(m.get_a11() + k, m.get_a12() + k,
                  m.get_a21() + k, m.get_a22() + k);
}

// scalar + matrix
matrix operator+(double k, const matrix& m) {
    return m + k;
}

// matrix - scalar
matrix operator-(const matrix& m, double k) {
    return matrix(m.get_a11() - k, m.get_a12() - k,
                  m.get_a21() - k, m.get_a22() - k);
}

// scalar - matrix
matrix operator-(double k, const matrix& m) {
    return matrix(k - m.get_a11(), k - m.get_a12(),
                  k - m.get_a21(), k - m.get_a22());
}

// matrix * scalar
matrix operator*(const matrix& m, double k) {
    return matrix(m.get_a11() * k, m.get_a12() * k,
                  m.get_a21() * k, m.get_a22() * k);
}

// scalar * matrix
matrix operator*(double k, const matrix& m) {
    return m * k;
}

}