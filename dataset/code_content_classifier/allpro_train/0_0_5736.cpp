#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s0, t;
    cin >> s0 >> t;

    vector<int> occurrences(n+1, 0);
    occurrences[0] = count(s0.begin(), s0.end(), t[0]);

    for (int i = 1; i <= n; i++) {
        occurrences[i] = occurrences[i-1] + count(s0.begin(), s0.end(), t[i-1]);
        occurrences[i] %= MOD;
        s0 = s0 + t[i-1] + s0;
    }

    for (int i = 0; i < q; i++) {
        int k;
        string w;
        cin >> k >> w;

        int count_w = 0;
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= occurrences[j]; l++) {
                size_t found = s0.find(w, l);
                if (found != string::npos) {
                    count_w++;
                    l = found + 1;
                } else {
                    break;
                }
            }
        }
        cout << count_w % MOD << endl;
    }

    return 0;
}