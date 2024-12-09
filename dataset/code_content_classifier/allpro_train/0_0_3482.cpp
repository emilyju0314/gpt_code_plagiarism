#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> w(k);
        for (int i = 0; i < k; i++) {
            cin >> w[i];
        }

        sort(a.begin(), a.end());

        long long sum = 0;
        int start = n - 1;
        for (int i = 0; i < k; i++) {
            sum += a[start] + a[start-w[i]];
            start -= w[i];
        }

        cout << sum << endl;
    }

    return 0;
}