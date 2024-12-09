#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        int odd_count = 0;

        for (int j = 0; j < n; j++) {
            cin >> a[j];
            if (a[j] % 2 != 0) {
                odd_count++;
            }
        }

        if (odd_count == 0 || odd_count == n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}