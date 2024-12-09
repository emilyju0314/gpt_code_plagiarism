#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;

    for (char i = 'a'; i <= 't'; ++i) {
        for (char j = i; j <= 't'; ++j) {
            int cnt = 0;
            unordered_map<char, int> freq;

            for (int k = 0; k < n; ++k) {
                if (s[k] == i || s[k] == j) {
                    cnt++;
                } else {
                    freq[s[k]]++;
                }
            }

            for (auto it : freq) {
                if (it.second > 0) {
                    if (freq.find(it.first) != freq.end()) {
                        cnt += it.second;
                    }
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}