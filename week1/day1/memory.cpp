#include <iostream>
using namespace std;

void Print(int a, int *b, int &c)
{
    cout << "Address of byValue: " << &a << endl;
    cout << "Address of byPointer: " << &b << endl;
    cout << "Address of byReference: " << &c << endl;
}

int main()
{
    int num = 8;
    cout << "Address in the main: " << &num << endl;
    Print(num, &num, num);
    return 0;
}