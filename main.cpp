#include <iostream>
#include "include/matrix.h"

int main() {
    Matrix test_matrix(3, 3, 1.0);
    test_matrix.print();
    test_matrix(1, 1) = 2;
    test_matrix.print();
    try{
        test_matrix(5,5) = 0;
    }
    catch(const std::invalid_argument& e){
        std::cout << e.what();
    }

    // test also ostream printing
    std::cout << "Sum" << std::endl;
    Matrix A(3, 3, 1.0);
    Matrix B(3, 3, 2.0);
    Matrix C = A + B;
    std::cout << C;
}