#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    string s;
    cin >> s;

    int lower = count_if(s.begin(), s.end(), [](char c){ return islower(c); });
    int upper = n - lower;

    int min_changes = min(lower, upper);

    int ans = min_changes;
    for (int i = 0; i <= k; i++) {
        int changes = 0;
        vector<int> diff(n+1);
        for (int j = 0; j < n; j++) {
            if ((j - l + 1 >= 0) && (diff[j - l + 1] % 2 == 1)) {
                if (islower(s[j - l])) lower++;
                else upper++;
            }
            if ((j - l >= 0) && (diff[j - l] % 2 == 1)) {
                if (islower(s[j - l])) lower--;
                else upper--;
            }
            if ((lower >= upper && isupper(s[j])) || (upper >= lower && islower(s[j]))) {
                if (islower(s[j])) lower--;
                    else upper--;
                diff[j+1]++;
                changes++;
            }
        }
        ans = min(ans, changes);
    }

    cout << ans << endl;

    return 0;
}