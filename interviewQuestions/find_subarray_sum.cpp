#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{

    vector<int> v; // vector to store the result, start and end index
    long long current_sum = arr[0]; // current sum of the subarray
    int start = 0; // start index of the subarray
    for (int i = 1; i <= n; i++)
    {
        while (current_sum > s && start < i - 1)
        {
            current_sum -= arr[start];
            start++;
        }
        if (current_sum == s)
        {
            v.push_back(start+1);
            v.push_back(i);
            return v;
        }
        if (i < n)
        {
            current_sum += arr[i];
        }
    }
    v.push_back(-1);
    return v;
}

int main()
{
    cout << "Test SubArray Sum Find: " << endl;
    int arr[] = {1, 2, 3, 7, 5}; // make integer array
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of array
    long long s = 12; // sum to be searched
    vector<int> v = subarraySum(arr, n, s); // call function, its return index of subarray
    if (v[0] == -1)
    {
        cout << "No subarray found" << endl;
    }
    else
    {
        cout << "Subarray found" << endl;
        cout << "Start index: " << v[0] << endl;
        cout << "End index: " << v[1] << endl;
    }
    cout << endl;
    return 0;
}