#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int maxProduct = INT_MIN;
    int maxColumn = -1;

    for (int j = 0; j < m; ++j) {
        int product = 1;
        for (int i = 0; i < n; ++i) {
            product *= A[i][j];
        }

        if (product > maxProduct) {
            maxProduct = product;
            maxColumn = j;
        }
    }

    for (int i = 0; i < n; ++i) {
        A[i][maxColumn] -= 3;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}