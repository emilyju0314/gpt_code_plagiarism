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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n/2; i++) {
            int x = a[n-i-1];
            int y = a[i];
            while (x % y == 0) {
                y++;
            }
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}