#include "vector.h"
#include <iostream>

namespace spencer {

// Constructor
vector::vector(double x1, double x2, bool is_row)
    : x1(x1), x2(x2), is_row(is_row) {}

// Getters
double vector::get_x1() const { return x1; }
double vector::get_x2() const { return x2; }
bool vector::get_is_row() const { return is_row; }

// Setters
void vector::set_x1(double val) { x1 = val; }
void vector::set_x2(double val) { x2 = val; }
void vector::set_is_row(bool val) { is_row = val; }

// Transpose: column -> row, row -> column
vector vector::transpose() const {
    return vector(x1, x2, !is_row);
}

// Print
void vector::print() const {
    if (is_row) {
        std::cout << "[" << x1 << " " << x2 << "]" << std::endl;
    } else {
        std::cout << "[" << x1 << std::endl;
        std::cout << " " << x2 << "]" << std::endl;
    }
}

// vector + vector
vector operator+(const vector& lhs, const vector& rhs) {
    return vector(lhs.get_x1() + rhs.get_x1(), 
                  lhs.get_x2() + rhs.get_x2(),
                  lhs.get_is_row());
}

// vector - vector
vector operator-(const vector& lhs, const vector& rhs) {
    return vector(lhs.get_x1() - rhs.get_x1(), 
                  lhs.get_x2() - rhs.get_x2(),
                  lhs.get_is_row());
}

// vector * vector
vector operator*(const vector& lhs, const vector& rhs) {
    return vector(lhs.get_x1() * rhs.get_x1(), 
                  lhs.get_x2() * rhs.get_x2(),
                  lhs.get_is_row());
}

// vector + scalar
vector operator+(const vector& v, double k) {
    return vector(v.get_x1() + k, v.get_x2() + k, v.get_is_row());
}

// scalar + vector
vector operator+(double k, const vector& v) {
    return v + k;
}

// vector - scalar
vector operator-(const vector& v, double k) {
    return vector(v.get_x1() - k, v.get_x2() - k, v.get_is_row());
}
// scalar - vector
vector operator-(double k, const vector& v) {
    return vector(k - v.get_x1(), k - v.get_x2(), v.get_is_row());
}

// vector * scalar
vector operator*(const vector& v, double k) {
    return vector(v.get_x1() * k, v.get_x2() * k, v.get_is_row());
}
// scalar * vector
vector operator*(double k, const vector& v) {
    return v * k;
}

}