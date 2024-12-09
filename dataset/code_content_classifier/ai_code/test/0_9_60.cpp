#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        map<long long, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            freq[a[i]]++;
        }

        long double k = (long double) sum / n;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            long long remaining_sum = sum - a[i];
            long double remaining_k = (long double) remaining_sum / (n - 1);

            if (freq.count(2 * k - a[i]) > 0) {
                count += freq[2 * k - a[i]];
            }
            if (remaining_k == k) {
                count += freq[a[i]] - 1;
            }
        }

        cout << count / 2 << endl;
    }

    return 0;
}