#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    v1.reserve(6);
    v1.push_back(2);
    v1.push_back(3);
    cout << v1.capacity() << endl;

    v1.shrink_to_fit();
    cout << v1.capacity() << endl;
}