#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            sum += a[j];
        }

        sort(a.begin(), a.end());

        if (sum <= k) {
            cout << "0\n";
        } else {
            long long steps = 0;
            for (int j = 0; j < n; j++) {
                long long diff = k - sum;
                if (diff <= 0) {
                    break;
                }
                steps += min((long long)a[j], diff);
                sum -= a[j];
            }
            cout << steps << "\n";
        }
    }

    return 0;
}