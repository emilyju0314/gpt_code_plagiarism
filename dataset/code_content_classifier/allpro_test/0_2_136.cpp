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

        vector<int> b(n);
        long long total_time = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            total_time += b[i];
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[(i + 1) % n] = b[i] - b[(i + n - 1) % n];
        }

        long long sum_a = 0;
        for (int i = 0; i < n; i++) {
            sum_a += a[i];
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if ((n * a[i]) != sum_a) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}