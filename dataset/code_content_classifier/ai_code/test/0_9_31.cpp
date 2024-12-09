#include <iostream>
#include <vector>

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

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                cout << -sum << " ";
            } else {
                cout << 1 << " ";
                sum += a[i];
            }
        }

        cout << endl;
    }

    return 0;
}