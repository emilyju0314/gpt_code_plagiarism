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
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> pos(n + 1);
        fill(pos.begin(), pos.end(), -1);

        bool possible = true;

        for (int i = 0; i < n; i++) {
            int x = p[i];
            a[i] = x;

            if (x < 0 || pos[x] != -1 || (i > 0 && x > a[i - 1])) {
                possible = false;
                break;
            }

            pos[x] = i;
        }

        if (!possible) {
            cout << "NO" << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}