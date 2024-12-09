#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<vector<int>, int> mp;
        int steps = 0;
        while (mp.find(a) == mp.end()) {
            mp[a] = steps;
            bool all_zeros = true;
            for (int i = 0; i < n; i++) {
                a[i] = a[i] & a[(i + n - d) % n];
                if (a[i] != 0) {
                    all_zeros = false;
                }
            }
            if (all_zeros) {
                cout << steps + 1 << endl;
                break;
            }
            steps++;
        }

        if (mp.find(a) != mp.end()) {
            cout << -1 << endl;
        }
    }

    return 0;
}