#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int smallestSubarraySize(vector<int>& nums, int N, int K) {
    unordered_map<int, int> count;
    int left = 0, right = 0, unique = 0, minLen = INT_MAX;
    
    while (right < N) {
        if (count[nums[right]] == 0) {
            unique++;
        }
        count[nums[right]]++;
        right++;
        
        while (unique == K) {
            minLen = min(minLen, right - left);
            if (--count[nums[left]] == 0) {
                unique--;
            }
            left++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int result = smallestSubarraySize(nums, N, K);
    cout << result << endl;
    
    return 0;
}