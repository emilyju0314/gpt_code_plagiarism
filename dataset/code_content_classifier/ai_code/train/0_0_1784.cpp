#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int count_k_interesting_pairs(vector<int>& nums, int k) {
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            // Calculate the number of differing bits
            int diff_bits = 0;
            int xor_val = nums[i] ^ nums[j];
            while(xor_val) {
                diff_bits += xor_val & 1;
                xor_val >>= 1;
            }

            // If the number of differing bits equals k, increment count
            if(diff_bits == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = count_k_interesting_pairs(nums, k);
    cout << result << endl;

    return 0;
}