#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        // Calculate a_i from b_i and sum
        a[i] = (2 * n * b[i] - sum) / n;
    }

    // Check if the sequence is valid
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
        if (total < b[i] || (total - b[i]) % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}