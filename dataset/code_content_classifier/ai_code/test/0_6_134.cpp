#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++) {
            if (a[i] % a[0] != 0) {
                cout << "0" << endl;
                break;
            }
            if (i == n - 1) {
                cout << a[0] << endl;
            }
        }
    }

    return 0;
}