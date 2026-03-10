#ifndef VECTOR_H
#define VECTOR_H

namespace spencer {

class vector {
private:
    double x1;
    double x2;
    bool is_row;    // true = row vector, false = column vector

public:
    // Default consructor with default argument values
    vector(double x1 = 1, double x2 = 1, bool is_row = false);

    // Getters
    double get_x1();
    double get_x2();
    bool get_is_row();

    // Setters
    void set_x1(double val);
    void set_x2(double val);
    void set_is_row(bool val);

    // Transpose
    vector transpose();

    // Print
    void print();
};

// Operator overloading: vector + vector
vector operator+(vector lhs, vector rhs);
// Operator overloading: vector - vector
vector operator-(vector lhs, vector rhs);
// Operator overloading: vector * vector
vector operator*(vector lhs, vector rhs);


// Operator overloading: vector + scalar
vector operator+(vector v, double k);
// Operator overloading: scalar + vector
vector operator+(double k, vector v);

// Operator overloading: vector - scalar
vector operator-(vector v, double k);
// Operator overloading: scalar - vector
vector operator-(double k, vector v);

// Operator overloading: vector * scalar
vector operator*(vector v, double k);
// Operator overloading: scalar * vector
vector operator*(double k, vector v);

}

#endif
