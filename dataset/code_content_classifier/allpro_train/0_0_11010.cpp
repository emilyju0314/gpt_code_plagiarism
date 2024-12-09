#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int multiply = nums[i] * nums[j];
            int power = 1;
            while (pow(power, k) < multiply) {
                power++;
            }

            if (pow(power, k) == multiply) {
                count += freq[nums[i]] * freq[nums[j]];
            }
        }
    }

    cout << count << endl;

    return 0;
}