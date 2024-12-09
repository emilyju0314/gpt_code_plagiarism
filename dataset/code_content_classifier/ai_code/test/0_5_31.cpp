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
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = 0; i < n-1; i++) {
            cout << "1 ";
            sum -= a[i];
        }
        cout << -sum << endl;
    }

    return 0;
}