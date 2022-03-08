#include <iostream>
#include <vector>

using namespace std;

int MissingNumber(vector<int> &array, int n)
{
    // Your code goes here
    int s = (n * (n + 1)) / 2;
    int sum = 0;
    for (auto i : array)
        sum += i;
    return s - sum;
}

int main()
{
    vector<int> array = {1,2,3,5};
    cout << MissingNumber(array, array.size() + 1);
    return 0;
}