#include <iostream>
#include <cmath>
// Natural Sum of Subarray, using Kadane's Algorithm
// contiguous sub-array with the largest sum
// Time Complexity: O(n)
using namespace std;

long long bigSumSubArray(int arr[], int n) {
    long long max_sum = 0L, current_sum = 0L;
    int max_element = -1e7;
    for (int i = 0; i < n; i++){
        current_sum += arr[i];
        if (current_sum > max_sum)
            max_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
        max_element = max(max_element, arr[i]);
    }
    return max_sum > 0 ? max_sum : max_element;
}

int main(){
    int array[] = {-3, -5, 2};
    int n = 3;
    cout << "The sum of the subarray is: " << bigSumSubArray(array, n) << endl;
}