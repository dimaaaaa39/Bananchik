#include "read.hpp"
#include "write.hpp"
#include "process.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace MatrixOps;

int main() {
    int n;
    cout << "Введите размер матрицы (n): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cerr << "Ошибка: n должно быть в диапазоне [1, 100]." << endl;
        return 1;
    }

    vector<vector<int>> matrix(n, std::vector<int>(n));

    readMatrix(matrix, n);

    if (processMatrix(matrix, n)) {
        cout << "Условие выполнено. Столбцы были отсортированы." << endl;
    } else {
        cout << "Условие не выполнено. Матрица осталась неизменной." << endl;
    }

    writeMatrix(matrix, n);

    return 0;
}