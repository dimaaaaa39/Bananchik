#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// функц сумма цифр числа
int digitSum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    sort(arr.begin(), arr.end(), [](int a, int b) {
        if (digitSum(a) != digitSum(b)) return digitSum(a) < digitSum(b); 
        if (a % 10 != b % 10) return a % 10 < b % 10;
        return a < b;
    });

   
    for (int x : arr) cout << x << " ";

    return 0;
}