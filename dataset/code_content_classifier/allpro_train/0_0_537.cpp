#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = s;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = s[i] - 'a' + 1; j < 26; j++) {
                count[s[i] - 'a']--;
                count[j]++;

                int sum = 0;
                for (int l = 0; l < 26; l++) {
                    sum += (k - count[l] % k) % k;
                }
                if (sum <= n - i - 1) {
                    ans[i] = j + 'a';
                    for (int l = i + 1; l < n; l++) {
                        ans[l] = 'a';
                    }
                    for (int l = 0; l < 26; l++) {
                        for (int m = 0; m < (k - count[l] % k) % k; m++) {
                            ans.push_back(l + 'a');
                        }
                    }
                    i = -1;
                    break;
                }
            }
            count[s[i] - 'a']--;
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += (k - count[i] % k) % k;
        }
        if (sum != 0) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}