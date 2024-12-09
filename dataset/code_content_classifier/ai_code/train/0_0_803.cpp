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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << 3 * n << endl;
        for (int i = 0; i < n; i += 2) {
            // Perform assignment a_i = a_i + a_j
            cout << "1 " << i + 1 << " " << i + 2 << endl;
            // Perform assignment a_j = a_j - a_i
            cout << "2 " << i + 1 << " " << i + 2 << endl;
            // Perform assignment a_i = a_i + a_j
            cout << "1 " << i + 1 << " " << i + 2 << endl;
            // Perform assignment a_j = a_j - a_i
            cout << "2 " << i + 1 << " " << i + 2 << endl;
            // Perform assignment a_i = a_i + a_j
            cout << "1 " << i + 1 << " " << i + 2 << endl;
            // Perform assignment a_j = a_j - a_i
            cout << "2 " << i + 1 << " " << i + 2 << endl;
        }
    }

    return 0;
}