#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s, t;
        cin >> s >> t;

        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string res = "";
        int index = 0;
        for (char c : t) {
            while (cnt[index] == 0) {
                index++;
            }
            while (index < c - 'a') {
                res += string(1, 'a' + index);
                cnt[index]--;
                index++;
            }
        }
        
        while (index < 26) {
            while (cnt[index] > 0) {
                res += string(1, 'a' + index);
                cnt[index]--;
            }
            index++;
        }

        cout << res << endl;
    }

    return 0;
}