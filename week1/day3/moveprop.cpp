// Write a function processData(vector<int> data) — call it with an lvalue, then with std::move(vec).
// Print the size of vec after the move to prove it was "stolen."

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> processData(vector<int> data)
{
    return data;
}

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2 = processData(v1);
    cout << "The size of v1 is " << v1.size() << endl;
    cout << "The size of v2 is " << v2.size() << endl;

    cout << "<----- Processing through move --------->" << endl;

    vector<int> v3 = processData(std::move(v1));
    cout << "The size of v1 is " << v1.size() << endl;
    cout << "The size of v3 is " << v2.size() << endl;
}