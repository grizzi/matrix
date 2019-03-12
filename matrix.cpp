#include "include/matrix.h"

Matrix::Matrix(unsigned const rowSize, unsigned const colSize, double initValue)
    :   m_rowSize(rowSize),
        m_colSize(colSize)

{
    m_matrix.resize(rowSize);
    for(size_t i = 0; i < rowSize; i++) {
        m_matrix[i].resize(colSize, initValue);
    }
}

Matrix Matrix::operator+(Matrix & B) {
    Matrix sum(m_rowSize, m_colSize, 0.0);
    for (size_t i = 0; i < m_rowSize; i++)
        for(size_t j = 0; j < m_colSize; j++)
            sum(i,j) = this->m_matrix[i][j] + B(i, j);

    return sum;
}

double& Matrix::operator()(const unsigned &rowIndex, const unsigned &colIndex) {
    if( rowIndex >= m_rowSize || colIndex >= m_colSize)
    {
        std::ostringstream oss;
        oss << "Too large row/column index, required [" << rowIndex << "][" << colIndex << "]" << std::endl;
        throw std::invalid_argument(oss.str());
    }
    return this->m_matrix[rowIndex][colIndex];
}

unsigned Matrix::getRows() const {
    return this->m_rowSize;
}

unsigned Matrix::getCols() const {
    return this->m_colSize;
}

void Matrix::print() const
{
    std::cout << "Matrix= " <<std::endl;
    for(size_t i = 0; i < m_rowSize; i++) {
        for(size_t j = 0; j < m_colSize; j++) {
            std::cout << "[ " << m_matrix[i][j] << " ] ";
        }
        std::cout << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, Matrix& M) {
    os << "Matrix= " << std::endl;
    for(size_t i = 0; i < M.getRows(); i++) {
        for(size_t j = 0; j < M.getCols(); j++) {
            os << "[ " << M(i, j) << " ] ";
        }
        os << std::endl;
    }
    return os;
}


