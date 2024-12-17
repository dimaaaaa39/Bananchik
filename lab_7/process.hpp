#include "process.hpp"
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
namespace MatrixOps {
    
    int sumOfDigits(int num) {
        int sum = 0;
        num = abs(num); 
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    void findMinMax(const vector<vector<int>>& matrix, int& minVal, int& maxVal) {
        minVal = matrix[0][0];
        maxVal = matrix[0][0];

        for (const auto& row : matrix) {
            for (int elem : row) {
                if (elem < minVal) minVal = elem;
                if (elem > maxVal) maxVal = elem;
            }
        }
    }

    
    void sortColumns(vector<vector<int>>& matrix, int n) {
        
        vector<pair<int, int>> columnSums;

        for (int col = 0; col < n; ++col) {
            int colSum = 0;
            for (int row = 0; row < n; ++row) {
                colSum += matrix[row][col];
            }
            columnSums.push_back({colSum, col});
        }

        sort(columnSums.begin(), columnSums.end());

        vector<vector<int>> sortedMatrix(n, vector<int>(n));
        for (int newCol = 0; newCol < n; ++newCol) {
            int oldCol = columnSums[newCol].second; 
            for (int row = 0; row < n; ++row) {
                sortedMatrix[row][newCol] = matrix[row][oldCol];
            }
        }

        matrix = sortedMatrix;
    }

    bool processMatrix(vector<vector<int>>& matrix, int n) {
        int minVal, maxVal;

        findMinMax(matrix, minVal, maxVal);

        int minSum = sumOfDigits(minVal);
        int maxSum = sumOfDigits(maxVal);

        if (abs(minSum - maxSum) <= 2) {
            sortColumns(matrix, n);
            return true;
        }

        return false;  
    }
}