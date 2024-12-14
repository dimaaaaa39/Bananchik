#include <iostream>
using namespace std;
//1)
int main(){
    int a, num, maxNumber = -1, maxIndex = -1;
    long long pow = 1;

    cout << "Введите количество чисел: ";
    cin >> a;

    cout << "Введите последовательность: ";
    for (int i = 1; i <= a; ++i) {
        cin >> num;

        if (num % 5 != 0) {
            pow *= num;
            if (num > maxNumber) {
                maxNumber = num;
                maxIndex = i;
            }
        }
    }

    if (maxNumber == -1) {
        cout << "Нет чисел, не делящихся на 5." << endl;
    } else {
        cout << "Произведение: " << pow << endl;
        cout << "Наибольшее число: " << maxNumber << endl;
        cout << "Его номер: " << maxIndex << endl;
    }


//2)

    long long n; 
    long long product = 1; 
    cout << "Введите число N: ";
    cin >> n;

    bool c = false; 

    while (n > 0) {
        int b = n % 10; 
        if (b % 2 != 0) { 
            product *= b;
            c = true;
        }
        n /= 10; 
    }

    if (c) {
        cout << product << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}