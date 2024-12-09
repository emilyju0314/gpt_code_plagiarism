#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long score = 0;
    for(int i = 0; i < n; i++) {
        score += (long long)nums[i] * (i + 2);
    }

    cout << score << endl;

    return 0;
}