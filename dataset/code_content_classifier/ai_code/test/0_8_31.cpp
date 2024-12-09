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

        int sum_a = 0;
        for (int i = 0; i < n; i++) {
            sum_a += a[i];
        }

        if (sum_a == 0) {
            for (int i = 0; i < n; i++) {
                cout << "1 ";
            }
        } else {
            int sum_b = 0;
            for (int i = 0; i < n-1; i++) {
                cout << "1 ";
                sum_b += 1;
            }
            cout << -sum_a + sum_b << endl;
        }

        cout << endl;
    }

    return 0;
}