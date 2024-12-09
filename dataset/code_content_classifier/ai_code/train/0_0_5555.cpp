#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;
    for(int i = 0; i < n-1; i++) {
        long long diff = (long long)nums[i+1] - nums[i];
        long long increase = (long long)(i+1) * diff;
        if(increase <= k) {
            k -= increase;
            min_diff = 0;
        } else {
            min_diff = min(min_diff, (int)(k / (i+1)));
            break;
        }
    }

    cout << min_diff << endl;

    return 0;
}