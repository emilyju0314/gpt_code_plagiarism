#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        if (sum <= k) {
            cout << 0 << endl;
        } else {
            sort(a.begin(), a.end(), greater<int>());
            long long steps = 0;
            for (int i = 0; i < n; i++) {
                if (i == n-1) {
                    steps += (k-sum);
                    break;
                }
                long long diff = a[i] - a[i+1];
                long long mult = min((k-sum)/(i+1), diff);
                steps += mult*(i+1);
                sum += mult*(i+1);
            }
            cout << steps << endl;
        }
    }

    return 0;
}