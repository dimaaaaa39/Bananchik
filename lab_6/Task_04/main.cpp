#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int sum = 0, temp = num;
        bool hasDuplicates = false;
        int digits[10] = {0};

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            if (++digits[digit] > 1) hasDuplicates = true;
            temp /= 10;
        }
        if (sum % 7 == 0) continue;

    
        result.push_back(num);
        if (hasDuplicates) result.push_back(num); 
    }

    for (int num : result) {
        cout << num << endl;
    }

    return 0;
}