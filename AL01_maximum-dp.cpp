/*
Use the divide-and-conquer approach to write a recursive algorithm that finds the
maximum sum in any contiguous sublist of a given list of n real values. Analyze
your algorithm, and show the results in order notation.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int sum(int* dp, int* arr, int size) {
    int maxSum = dp[0] = arr[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        if(dp[i] > maxSum) maxSum = dp[i];
    }
    return maxSum;
}

int main() {
    int arr[10] = {2, 1, -4, 3, 4, -4, 6, 5, -5, 1};
    int dp[10] = {0, };
    int maxSum = sum(dp, arr, 10);
    for(int i=0; i<10; i++) cout << dp[i] << " ";

    cout << endl << maxSum << endl;
    return 0;
}