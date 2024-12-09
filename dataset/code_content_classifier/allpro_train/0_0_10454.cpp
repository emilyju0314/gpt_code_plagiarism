#include <iostream>
#include <vector>

using namespace std;

int countSets(int N, int K, int S, int T, vector<int>& nums) {
    int ans = 0;
    for (int i = 1; i < (1 << N); i++) {
        vector<int> subset;
        int and_result = -1;
        int or_result = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                and_result = (and_result == -1) ? nums[j] : (and_result & nums[j]);
                or_result |= nums[j];
                subset.push_back(nums[j]);
            }
        }
        if (subset.size() >= 1 && subset.size() <= K && and_result == S && or_result == T) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int N, K, S, T;
    cin >> N >> K >> S >> T;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int result = countSets(N, K, S, T, nums);
    cout << result << endl;
    
    return 0;
}