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
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum == 0) {
            cout << "NO" << endl;
        } else {
            sort(a.begin(), a.end());

            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (i != 0) {
                    cout << " ";
                }
                cout << a[i];
            }
            cout << endl;
        }
    }

    return 0;
}