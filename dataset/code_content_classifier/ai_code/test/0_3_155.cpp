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

        sort(liked.begin(), liked.end(), greater<int>());
        sort(disliked.begin(), disliked.end(), greater<int>());

        vector<int> q(n);
        int i = 0, j = 0;
        for (int k = 0; k < n; k++) {
            if (s[k] == '1') {
                q[k] = liked[i++];
            } else {
                q[k] = disliked[j++];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}