#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<pair<int, int>> operations;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                if(cnt < k) {
                    // Reverse the substring to make it regular
                    for(int j = i; j < n; j++) {
                        if(s[j] == '(') {
                            reverse(s.begin() + i, s.begin() + j + 1);
                            operations.push_back({i + 1, j + 1});
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }

        cout << operations.size() << endl;
        for(auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}