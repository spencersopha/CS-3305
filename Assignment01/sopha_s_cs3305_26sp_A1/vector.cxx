// Spencer Sopha
// Buff ID: 1093171
// DSA - A1

#include "vector.h"
#include <iostream>

namespace sopha {
    // Default construtor
    vector::vector(double x1, double x2, bool is_row) {
        x1 = x1;
        x2 = x2;
        is_row = is_row;
    }

    // Tranpose function: column => row, row => column
    vector vector::transpose() {
        return vector(x1, x2, !is_row);
    }

    // Print the vector in row or column format based on is_row
    void vector::print() {
        if (!is_row) {
            std::cout << "[" << x1 << " " << x2 << "]" << "\n";
        } else {
            std::cout << "[" << x1 << "\n";
            std::cout << " " << x2 << "]" << "\n";
        }
    }

    // Getters
    double vector::get_x1() { return x1; }
    double vector::get_x2() { return x2; }
    bool vector::get_is_row() { return is_row; }

    // Setters
    void vector::set_x1(double val) { x1 = val; }
    void vector::set_x2(double val) { x2 = val; }
    void vector::set_is_row(bool val) { is_row = val; }

    // Overladed operators
    // scalar + vector
    vector operator+(double k, vector v) {    
        return vector(k + v.get_x1(), k + v.get_x2(), v.get_is_row());
    }

    // vector + scalar
    vector operator+(vector v, double k) {    
        return vector(v.get_x1() + k, v.get_x2() + k, v.get_is_row());
    }

    // scalar - vector
    vector operator-(double k, vector v) {    
         return vector(k - v.get_x1(), k - v.get_x2(), v.get_is_row());
    }

    // vector - scalar
    vector operator-(vector v, double k) {    
        return vector(v.get_x1() - k, v.get_x2() - k, v.get_is_row());
    }

    // scalar * vector
    vector operator*(double k, vector v) {    
        return vector(k * v.get_x1(), k * v.get_x2(), v.get_is_row());
    }

    // vector * scalar
    vector operator*(vector v, double k) {    
        return vector(v.get_x1() * k, v.get_x2() * k, v.get_is_row());
    }

    // vector + vector
    vector operator+(vector v1, vector v2) {    
        return vector(v1.get_x1() + v2.get_x1(),
                      v1.get_x2() + v2.get_x2(),
                      v1.get_is_row());
    }

    // vector - vector
    vector operator-(vector v1, vector v2) {    
        return vector(v1.get_x1() - v2.get_x1(),
                      v1.get_x2() - v2.get_x2(),
                      v1.get_is_row());
    }

    // vector * vector
    vector operator*(vector v1, vector v2) {    
        return vector(v1.get_x1() * v2.get_x1(),
                      v1.get_x2() * v2.get_x2(),
                      v1.get_is_row());
    }
}
