#ifndef vector_h
#define vector_h

namespace spencer {

class vector {
private:
    double x1;
    double x2;
    bool is_row;    // true = row vector, false = column vector

public:
    // Default constructor with default argument values
    vector(double x1 = 1, double x2 = 1, bool is_row = false);

    // Getters
    double get_x1() const;
    double get_x2() const;
    bool get_is_row() const;

    // Setters
    void set_x1(double val);
    void set_x2(double val);
    void set_is_row(bool val);

    // Transpose
    vector transpose() const;

    // Void
    void print() const;
};

// Operator overloading: vector + vector
vector operator+(const vector& lhs, const vector& rhs);
// Operator overloading: vector - vector
vector operator-(const vector& lhs, const vector& rhs);
// Operator overloading: vector * vector
vector operator*(const vector& lhs, const vector& rhs);


// Operator overloading: vector + scalar
vector operator+(const vector& v, double k);
// Operator overloading: scalar + vector
vector operator+(double k, const vector& v);

// Operator overloading: vector - scalar
vector operator-(const vector& v, double k);
// Operator overloading: scalar - vector
vector operator-(double k, const vector& v);

// Operator overloading: vector * scalar
vector operator*(const vector& v, double k);
// Operator overloading: scalar * vector
vector operator*(double k, const vector& v);

}

#endif
