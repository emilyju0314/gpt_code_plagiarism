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

        vector<int> ans(n);

        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans[i] = liked[j++];
            } else {
                ans[i] = disliked[k++];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}