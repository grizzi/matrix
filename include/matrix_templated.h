#ifndef MATRIX_MATRIX_TEMPLATED_H

#include <vector>
#include <tuple>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T=double>
class Matrixt{

private:
    unsigned m_rowSize;
    unsigned m_colSize;
    std::vector<std::vector<T> > m_matrix;

public:
    // Constructors
    Matrixt(unsigned, unsigned, T);
    Matrixt(const char *);
    Matrixt(const Matrixt &);
    ~Matrixt() = default;

    // Matrix operators
    Matrixt operator+(Matrixt &);
    Matrixt operator-(Matrixt &);
    Matrixt operator*(Matrixt &);
    Matrixt transpose();

    // Scalar operators
    Matrixt operator+(T);
    Matrixt operator-(T);
    Matrixt operator*(T);
    Matrixt operator/(T);

    // Aesthetic operators

    // returns the reference so that we can directly access and change the element
    T& operator()(const unsigned &, const unsigned &);

    // using const keyword we do not allow these functions to change the members of the class they belong
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;

    // Power Iteration
    std::tuple<Matrixt, double, int> powerIter(unsigned, double);

    // Deflation
    Matrixt deflation(Matrixt &, double&);

};

template<typename T>
std::ostream& operator<<(std::ostream&, Matrixt<T>&);

// Constructors
template<typename T>
Matrixt<T>::Matrixt(unsigned const rowSize, unsigned const colSize, T initValue)
        :   m_rowSize(rowSize),
            m_colSize(colSize)

{
    m_matrix.resize(rowSize);
    for(size_t i = 0; i < rowSize; i++) {
        m_matrix[i].resize(colSize, initValue);
    }
}

// Matrix operators
template<typename T>
Matrixt<T> Matrixt<T>::operator+(Matrixt<T>& B) {
    Matrixt sum(m_rowSize, m_colSize, 0.0);
    for (size_t i = 0; i < m_rowSize; i++)
        for(size_t j = 0; j < m_colSize; j++)
            sum(i,j) = this->m_matrix[i][j] + B(i, j);

    return sum;
}

template<typename T>
Matrixt<T> Matrixt<T>::transpose() {
    Matrixt t(m_rowSize, m_colSize, 0.0);
    for(size_t i = 0; i < m_rowSize; i++)
        for(size_t j = 0; j < m_colSize; j++)
            t(i,j) = this->m_matrix[j][i];
    return t;

}

template<typename T>
T& Matrixt<T>::operator()(const unsigned &rowIndex, const unsigned &colIndex) {
    if( rowIndex >= m_rowSize || colIndex >= m_colSize)
    {
        std::ostringstream oss;
        oss << "Too large row/column index, required [" << rowIndex << "][" << colIndex << "]" << std::endl;
        throw std::invalid_argument(oss.str());
    }
    return this->m_matrix[rowIndex][colIndex];
}

template<typename T>
unsigned Matrixt<T>::getRows() const {
    return this->m_rowSize;
}

template<typename T>
unsigned Matrixt<T>::getCols() const {
    return this->m_colSize;
}

template<typename T>
void Matrixt<T>::print() const
{
    std::cout << "Matrix= " <<std::endl;
    for(size_t i = 0; i < m_rowSize; i++) {
        for(size_t j = 0; j < m_colSize; j++) {
            std::cout << "[ " << m_matrix[i][j] << " ] ";
        }
        std::cout << std::endl;
    }
}

// TEMPLATE SPECIALIZATION for char matrices
template <>
class Matrixt <char>{
private:
    unsigned m_rowSize;
    unsigned m_colSize;
    std::vector<std::vector<char> > m_matrix;
public:
    Matrixt(unsigned rowSize, unsigned colSize, char initValue);
    Matrixt(Matrixt&);
    ~Matrixt() = default;

    char& operator()(unsigned rowIndex, unsigned colIndex);
    unsigned getRows() const;
    unsigned getCols() const;

};

Matrixt<char>::Matrixt(unsigned rowSize, unsigned colSize, char initValue)
:   m_rowSize(rowSize),
    m_colSize(colSize)
{
    m_matrix.resize(rowSize);
    for(size_t i = 0; i < rowSize; i++){
        m_matrix[i].resize(colSize, initValue);
    }
}

char& Matrixt<char>::operator()(unsigned rowIndex, unsigned colIndex){
    return m_matrix[rowIndex][colIndex];
}

unsigned Matrixt<char>::getRows() const {
    return m_rowSize;
}

unsigned Matrixt<char>::getCols() const {
    return m_colSize;
}

// printing
template<typename T>
std::ostream& operator<<(std::ostream& os, Matrixt<T>& M) {
    os << "Matrix= " << std::endl;
    for(size_t i = 0; i < M.getRows(); i++) {
        for(size_t j = 0; j < M.getCols(); j++) {
            os << "[ " << M(i, j) << " ] ";
        }
        os << std::endl;
    }
    return os;
}

#define MATRIX_MATRIX_TEMPLATED_H

#endif //MATRIX_MATRIX_TEMPLATED_H
