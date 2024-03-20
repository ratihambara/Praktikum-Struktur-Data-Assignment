#include <iostream>
using namespace std;
// main program
int main()
{
    char op;
    float num1, num2;
    cout<<"Masukkan Operator: ";
    cin>>op;
    cout<<"\nMasukkan Bilangan ke-1 dan ke-2: ";
    cin>>num1>>num2;

    switch(op)
    {
    case '+':
        cout<< num1+num2;
        break;
    case '-':
        cout<< num1-num2;
    case '*':
        cout<< num1*num2;
    case '/':
        cout<< num1/num2;
    default:
        cout<< "Error! operator is not correct";
    }
return 0;
}