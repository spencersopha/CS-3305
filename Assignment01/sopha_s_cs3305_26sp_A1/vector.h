// Spencer Sopha
// Buff ID: 1093171
// DSA - A1

#ifndef VECTOR_H
#define VECTOR_H

namespace sopha {
    class vector {
        private:
            double x1, x2;
            bool is_row;    // true = row vector, false = column vector

        public:
            // Default constructor with default argument values
            vector (double x1=0, double x2=0, bool is_row=false);

            // Transpose function to return a new vector with transposed orientation
            vector transpose();

            // Print function to display the vectors
            void print();

            // Getters for the vector components
            double get_x1();
            double get_x2();
            bool get_is_row();

            // Setters for the vector components
            void set_x1(double val);
            void set_x2(double val);
            void set_is_row(bool val);
    };

    // Overladed operators for vector addition, subtraction, and multiplication
    vector operator+(double k, vector v);    // scalar + vector
    vector operator+(vector v, double k);    // vector + scalar

    vector operator-(double k, vector v);    // scalar - vector
    vector operator-(vector v, double k);    // vector - scalar

    vector operator*(double k, vector v);    // scalar * vector
    vector operator*(vector v, double k);    // vector * scalar

    vector operator+(vector v1, vector v2);    // vector + vector
    vector operator-(vector v1, vector v2);    // vector - vector
    vector operator*(vector v1, vector v2);    // vector * vector

#endif

}
