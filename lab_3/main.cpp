#include <iostream>
using namespace std;
int main()
 {
    unsigned int x; 
    int i;      
    cin >> x;
    cin >> i;
    if (i < 0 || i >= 32) {
        cout << "Индекс i должен быть от 0 до 31." << endl;
        return 1;
    }
    x = x & ~(1U << i);
    cout << x;
    return 0;
}
