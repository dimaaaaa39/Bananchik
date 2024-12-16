#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool allDigitsSame(int num) {
    while (num % 10 == (num /= 10) % 10 && num > 0);
    return num == 0;
}

int main() {
    int n, count = 0;
    cin >> n;
    vector<int> arr(n);

    for (int &x : arr) {
        cin >> x;
        count += allDigitsSame(x);
    }

    if (count >= 3) sort(arr.rbegin(), arr.rend());
    for (int x : arr) cout << x << " ";

    return 0;
}
