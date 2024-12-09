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

        int max_min = a[0];
        for (int i = 1; i < n; i++) {
            max_min = max(max_min, (a[i] - a[0]) % n);
        }

        cout << max_min << endl;
    }

    return 0;
}