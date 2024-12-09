#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(4 * n);
    for(int i = 0; i < 4 * n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long beauty = 0;
    for(int i = 0; i < n; i++) {
        beauty += nums[2 * n + 2 * i];
    }

    cout << beauty << endl;

    return 0;
}