#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxOnes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int ones = 0;
            for (int k = 0; k < n; k++) {
                if (k >= i && k <= j) {
                    ones += 1 - nums[k];
                } else {
                    ones += nums[k];
                }
            }
            maxOnes = max(maxOnes, ones);
        }
    }

    cout << maxOnes << endl;

    return 0;
}