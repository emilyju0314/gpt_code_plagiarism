#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        string s;
        cin >> s;

        vector<int> liked, disliked;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                liked.push_back(p[i]);
            } else {
                disliked.push_back(p[i]);
            }
        }

        sort(liked.rbegin(), liked.rend());
        sort(disliked.rbegin(), disliked.rend());

        vector<int> q(n);
        int l = 0, d = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                q[i] = liked[l++];
            } else {
                q[i] = disliked[d++];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}