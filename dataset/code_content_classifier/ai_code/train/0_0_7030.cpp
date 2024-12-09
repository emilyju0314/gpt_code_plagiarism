#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        vector<int> p(n);
        vector<bool> taken(n + 1, false);

        for (int i = 0; i < 2 * n; i++) {
            if (!taken[a[i]]) {
                p.push_back(a[i]);
                taken[a[i]] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}