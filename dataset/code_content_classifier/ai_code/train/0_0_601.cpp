#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int total_cost = 0;
    for(int i=0; i<n; i++) {
        total_cost += nums[i] * i;
    }

    cout << total_cost << endl;

    return 0;
}