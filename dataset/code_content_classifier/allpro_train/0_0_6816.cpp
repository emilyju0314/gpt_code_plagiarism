#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculateXOR(vector<long long>& nums) {
    long long res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    long long maxBeauty = 0;
    for (int i = 0; i < N; i++) {
        vector<long long> red, blue;
        for (int j = 0; j < N; j++) {
            if (j == i) {
                red.push_back(nums[j]);
            } else {
                blue.push_back(nums[j]);
            }
        }
        maxBeauty = max(maxBeauty, calculateXOR(red) + calculateXOR(blue));
    }

    cout << maxBeauty << endl;

    return 0;
}