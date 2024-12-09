#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> first_occ(26, -1);
        vector<int> last_occ(26, -1);

        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(first_occ[c] == -1) {
                first_occ[c] = i;
            }
            last_occ[c] = i;
        }

        int ans = n;

        for(int c = 0; c < 26; c++) {
            if(first_occ[c] == -1) {
                continue;
            }

            int cur_ans = 0;

            for(int i = 0; i < 26; i++) {
                if(first_occ[i] == -1) {
                    continue;
                }

                if(c == i) {
                    continue;
                }

                cur_ans = max(cur_ans, max(first_occ[i], n - 1 - last_occ[i]));
            }

            ans = min(ans, cur_ans);
        }

        if(ans == n) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}