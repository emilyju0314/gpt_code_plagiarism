#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s, t;
        cin >> s >> t;

        vector<int> cnt(26, 0);
        for(char c : s) {
            cnt[c - 'a']++;
        }

        string result;
        int idx = 0;
        for(char c : t) {
            while (cnt[idx] == 0) {
                idx++;
            }
            while (cnt[idx] > 0) {
                result.push_back(idx + 'a');
                cnt[idx]--;
            }
        }

        for(int i = 0; i < 26; i++) {
            while(cnt[i] > 0) {
                result.push_back(i + 'a');
                cnt[i]--;
            }
        }

        cout << result << endl;
    }

    return 0;
}