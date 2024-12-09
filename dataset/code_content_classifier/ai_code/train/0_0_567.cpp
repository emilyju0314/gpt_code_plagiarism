#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        string s;
        cin >> s;

        int n = s.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                cnt[idx]++;
                int max_freq = *max_element(cnt.begin(), cnt.end());
                ans += max_freq;
            }
        }

        cout << ans << endl;
    }

    return 0;
}