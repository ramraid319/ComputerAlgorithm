#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums, int target) {
    int n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true; // 0을 만들 수 있는 경우 (아무 숫자도 선택하지 않은 경우)

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int splitArray(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) return 0; // 전체 합이 짝수가 아니면 불가능

    int target = totalSum / 2;
    sort(nums.begin(), nums.end());

    // 이진 탐색으로 최대한 비슷한 부분 합 찾기
    int left = *max_element(nums.begin(), nums.end());
    int right = totalSum;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canPartition(nums, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> nums = {1, 6, 11, 5}; // 입력 리스트 예시
    int minDiff = splitArray(nums);
    int maxSubsetSum1 = minDiff;
    int maxSubsetSum2 = accumulate(nums.begin(), nums.end(), 0) - maxSubsetSum1;

    cout << "부분 리스트의 최대 합: " << maxSubsetSum1 << ", " << maxSubsetSum2 << endl;

    return 0;
}
