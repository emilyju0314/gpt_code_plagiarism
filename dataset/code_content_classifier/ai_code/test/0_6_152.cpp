#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<int> a(n, 0);
        bool bipartite = true;

        for (int i = 0; i < n; i++) {
            cin >> p[i];

            if (i > 0 && p[i] < p[i-1]) {
                bipartite = false;
            }
        }

        if (!bipartite) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (i > 0 && p[i] > p[i-1]) {
                    a[i] = a[i-1];
                } else {
                    a[i] = -p[i];
                }
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}