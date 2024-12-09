#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;
        
        string s;
        cin >> s;

        int sum = 0;
        for(char c : s) {
            if (c == '0') {
                sum++;
            } else {
                sum--;
            }
        }

        vector<int> prefix_sum((int) s.size() * 2 + 1);
        int cur_sum = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            prefix_sum[i + 1] = cur_sum;
            if (s[i] == '0') {
                cur_sum++;
            } else {
                cur_sum--;
            }
        }

        int ans = 0;
        if (sum == 0) {
            bool found = false;
            for (int i = 0; i < (int)s.size(); i++) {
                if (prefix_sum[i] == x) {
                    found = true;
                }
            }
            if (found) {
                ans = -1;
            } else {
                ans = 0;
            }
        } else if (sum > 0) {
            for (int i = 0; i < (int)s.size(); i++) {
                if ((x - prefix_sum[i]) % sum == 0 && (x - prefix_sum[i]) / sum >= 0) {
                    ans++;
                }
            }
        } else {
            sum = -sum;
            for (int i = 0; i < (int)s.size(); i++) {
                if ((prefix_sum[i] - x) % sum == 0 && (prefix_sum[i] - x) / sum >= 0) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}