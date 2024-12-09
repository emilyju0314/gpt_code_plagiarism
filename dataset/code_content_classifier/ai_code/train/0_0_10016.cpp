#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int operations = 0;
    int currentMex = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == currentMex) {
            currentMex++;
        } else {
            operations++;
        }
    }

    if(nums[n-1] == currentMex) {
        operations += (x != currentMex);
    } else {
        operations += (x != currentMex + 1);
    }

    cout << operations << endl;

    return 0;
}