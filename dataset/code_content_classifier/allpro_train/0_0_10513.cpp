#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string t;
    cin >> t;

    int n = t.size();
    long long ans = 0;

    vector<int> cnt(26, 0);

    for (int i = 0; i < n; ++i) {
        ++cnt[t[i] - 'a'];

        int maxFreq = 0, sumFreq = 0, oddFreq = 0;

        for (int j = 0; j < 26; ++j) {
            if (cnt[j] == maxFreq) {
                sumFreq += cnt[j];
            } else if (cnt[j] > maxFreq) {
                maxFreq = cnt[j];
                sumFreq = cnt[j];
            }

            if (cnt[j] % 2 == 1) {
                ++oddFreq;
            }

            if (oddFreq <= 1) {
                ans += sumFreq;
            }
        }
    }

    cout << ans << endl;

    return 0;
}