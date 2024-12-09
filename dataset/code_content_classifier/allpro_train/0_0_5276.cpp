#include <iostream>
#include <vector>
using namespace std;

long long int countSubsets(vector<int>& nums, int idx, long long int cur_sum, long long int& total_count, int P) {
    if (idx == nums.size()) {
        if (cur_sum % 2 == 0) {
            total_count++;
        }
    } else {
        countSubsets(nums, idx + 1, cur_sum + nums[idx], total_count, P);
        countSubsets(nums, idx + 1, cur_sum, total_count, P);
    }
    return total_count % P;
}

int main() {
    int A, B, P;
    while (true) {
        cin >> A >> B >> P;
        if (A == 0 && B == 0 && P == 0) {
            break;
        }
        
        vector<int> nums;
        for (int i = A; i <= B; i++) {
            nums.push_back(i);
        }

        long long int total_count = 0;
        total_count = countSubsets(nums, 0, 0, total_count, P);
        cout << total_count << endl;
    }

    return 0;
}