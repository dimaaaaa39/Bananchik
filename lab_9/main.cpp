#include <iostream>
using namespace std;
int main() {
    int number; // Целое число
    cout << "Введите целое число: ";
    cin >> number;

    unsigned char* bytePointer = reinterpret_cast<unsigned char*>(&number);

    cout << "Содержимое каждого байта числа " << number << " (от младшего к старшему):" <<endl;

    for (size_t i = 0; i < sizeof(int); ++i) {
        cout << "Байт " << i << ": " << static_cast<int>(bytePointer[i]) <<endl;
    }

    return 0;
}