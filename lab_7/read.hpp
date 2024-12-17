#include "read.hpp"
#include <iostream>
using namespace std;
namespace MatrixOps {
    void readMatrix(vector<std::vector<int>> &matrix, int n) {
        cout << "Введите элементы матрицы (" << n << "x" << n << "):" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
    }
