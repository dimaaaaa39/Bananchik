#include <iostream>
using namespace std;
int main() {
    //1)
    int A, B, C; 
    cout<<"Введите значения A,B,C :";
    cin >> A >> B >> C;
    if (A % C == 0 && B % C == 0) {
        cout << (A + B) / C <<endl;
    } else if (A % C == 0 && B % C != 0) {
        cout<< (A / C) + B << endl;
    } else {
        cout << A - B - C <<endl;
    }
    //2)
    int N;
    cout << "Введите цифру от 0 до 9 (N): ";
    cin >> N;
    switch (N) {
        case 0: cout << "Ноль" << endl; break;
        case 1: cout << "Один" << endl; break;
        case 2: cout << "Два" << endl; break;
        case 3: cout << "Три" << endl; break;
        case 4: cout << "Четыре" << endl; break;
        case 5: cout << "Пять" << endl; break;
        case 6: cout << "Шесть" << endl; break;
        case 7: cout << "Семь" << endl; break;
        case 8: cout << "Восемь" << endl; break;
        case 9: cout << "Девять" << endl; break;
        default:cout << "Ошибка: введено недопустимое значение!" <<endl; break;
    }
    //3)
    int x;
    cout << "Введите значиния x = 1 или x = -1: ";
    cin >> x;
    if (x == -1) {
        cout << "Negative number" << endl;
    } else if (x == 1) {
        cout << "Positive number" << endl;
    } else {
        cout << "Ошибка: x может равен только '1' или '-1' " << endl;
    }

    return 0;
}
