#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        map<int, int> freq;
        int cnt = 0;

        for (int j = i; j < n; j++) {
            freq[nums[j]]++;
            if (freq[nums[j]] > 1) {
                break;
            }
            cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << (n - ans) << endl;

    return 0;
}