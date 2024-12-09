#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> ans(n + 1, 1);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                ans[i + 1] += ans[i];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == 'R') {
                ans[i] += ans[i + 1];
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}