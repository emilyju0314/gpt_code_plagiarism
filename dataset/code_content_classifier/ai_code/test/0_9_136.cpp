#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        vector<int> a(n);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum += b[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                a[i] = (b[i] + b[(i + 1) % n]) / n;
            } else {
                a[i] = (b[(i - 1) % n] + b[i]) / n;
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++){
            if (a[i] * n != b[i] + b[(i + 1) % n]) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}