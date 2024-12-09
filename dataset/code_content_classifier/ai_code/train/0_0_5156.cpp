#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit <= 30; bit++) {
            int target = (1 << bit) - nums[i];
            if (freq.count(target)) {
                count += freq[target];
            }
        }
        freq[nums[i]]++;
    }

    cout << count << endl;

    return 0;
}