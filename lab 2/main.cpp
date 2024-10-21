#include <iostream>
using namespace std;
int main()
{
short a;
cout<<"Введите сторону куба ";
cin>>a;
if (a>0 && a<40){
    cout<<a*a*a;
}
else{
    cout<<"Введите значение в диапозоне от '1' до '39'!";
}
return 0;
}
