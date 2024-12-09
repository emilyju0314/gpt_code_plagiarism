#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> nums(n);
    set<int> numSet;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        numSet.insert(nums[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (numSet.count(a - nums[i]) && numSet.count(b - nums[i])) {
            cout << "NO" << endl;
            return 0;
        } else if (numSet.count(a - nums[i])) {
            ans[i] = 0;
        } else {
            ans[i] = 1;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}