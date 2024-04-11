/*
Use the divide-and-conquer approach to write a recursive algorithm that finds the
maximum sum in any contiguous sublist of a given list of n real values. Analyze
your algorithm, and show the results in order notation.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dncSum(const vector<int>& vec, int lo, int hi) {
    if(lo==hi)              // len == 1
        return vec[lo];
    int mid = (lo + hi) / 2;    // split vec
    int left = INT_MIN, right = INT_MIN, sum = 0;
    for(int i=mid;i>=lo;i--) {
        sum+=vec[i];
        left=max(left, sum);
    }
    sum=0;
    for(int i=mid+1;i<=hi;i++) {
        sum+=vec[i];
        right=max(right, sum);
    }
    int single = max(dncSum(vec,lo,mid), dncSum(vec,mid+1,hi));
    return max(left+right, single);
}

int main() {
    vector<int> arr = {2, 1, -4, 3, 4, -4, 6, 5, -5, 1};
    int maxSum = dncSum(arr, 1, 10);
    for(auto it:arr) cout << it << " ";

    cout << endl << maxSum << endl;
    return 0;
}