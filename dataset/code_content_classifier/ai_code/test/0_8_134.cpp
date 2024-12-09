#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_beautiful(vector<long long>& a, long long d) {
    for (int i = 1; i < a.size(); i++) {
        if ((a[i] % d == 0 && a[i-1] % d == 0) || (a[i] % d != 0 && a[i-1] % d != 0)) {
            return false;
        }
    }
    return true;
}

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

        for (int j = 1; j <= 100; j++) {
            if (is_beautiful(a, j)) {
                cout << j << endl;
                break;
            }
            if (j == 100) {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}