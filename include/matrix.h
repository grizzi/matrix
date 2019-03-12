#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>
#include <tuple>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

class Matrix{

private:
    unsigned m_rowSize;
    unsigned m_colSize;
    std::vector<std::vector<double> > m_matrix;

public:
    // Constructors
    Matrix(unsigned, unsigned, double);
    Matrix(const char *);
    Matrix(const Matrix &);
    ~Matrix() = default;

    // Matrix operators
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpose();

    // Scalar operators
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);

    // Aesthetic operators

    // returns the reference so that we can directly access and change the element
    double& operator()(const unsigned &, const unsigned &);

    // using const keyword we do not allow these functions to change the members of the class they belong
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;

    // Power Iteration
    std::tuple<Matrix, double, int> powerIter(unsigned, double);

    // Deflation
    Matrix deflation(Matrix &, double&);

};

std::ostream& operator<<(std::ostream&, Matrix&);

#endif //MATRIX_MATRIX_H
