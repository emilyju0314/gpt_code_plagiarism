#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> mp;
        int cur = a[n-1];
        mp[cur] = n-1;

        for (int i = n-2; i >= 0; i--) {
            if (a[i] > cur) {
                cur = a[i];
            }
            mp[cur] = i;
        }

        int changes = 0;
        cur = a[0];

        for (int i = 0; i < n; i++) {
            changes = max(changes, mp[cur]-i);
            cur = max(cur, a[i]);
        }

        cout << changes << endl;
    }

    return 0;
}