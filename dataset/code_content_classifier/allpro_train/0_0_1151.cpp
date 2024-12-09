#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2 * n + 1, 0);
        vector<int> is_present(n + 1, 0);
        vector<int> pos(2 * n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            is_present[a[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            cin >> a[i + n];
            is_present[a[i + n]]++;
        }

        bool impossible = false;
        for (int i = 1; i <= n; i++) {
            if (is_present[i] != 2) {
                cout << "-1\n";
                impossible = true;
                break;
            }
        }

        if (impossible) continue;

        vector<int> ans;
        map<int, int> flag;

        for (int i = 1; i <= n; i++) {
            if (flag[a[i]]) {
                ans.push_back(pos[a[i]]);
                ans.push_back(i);
            } else {
                flag[a[i]]++;
                pos[a[i]] = i;
            }
        }

        cout << ans.size() / 2 << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}