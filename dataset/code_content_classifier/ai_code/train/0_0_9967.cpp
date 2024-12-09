#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> perm(n);
        vector<int> increasing, decreasing;

        for (int i = 0; i < n; i++) {
            cin >> perm[i];
        }

        vector<int> dp(n+1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (perm[j] < perm[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int max_len = *max_element(dp.begin(), dp.end());

        cout << max_len << endl;

        increasing.clear();
        decreasing.clear();

        int current_len = max_len;
        for (int i = n-1; i >= 0; i--) {
            if (dp[i] == current_len) {
                increasing.push_back(perm[i]);
                current_len--;
            } else {
                decreasing.push_back(perm[i]);
            }
        }

        reverse(increasing.begin(), increasing.end());
        reverse(decreasing.begin(), decreasing.end());

        for (int i = 0; i < increasing.size(); i++) {
            if (i == 0 || increasing[i] > increasing[i-1]) {
                cout << increasing.size() - i;
                for (int j = i; j < increasing.size(); j++) {
                    cout << " " << increasing[j];
                }
                cout << endl;
            }
        }

        for (int i = 0; i < decreasing.size(); i++) {
            cout << "1 " << decreasing[i] << endl;
        }
    }

    return 0;
}