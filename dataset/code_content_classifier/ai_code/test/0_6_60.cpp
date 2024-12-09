#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long total_sum = 0;
        unordered_map<long long, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_sum += a[i];
            freq[a[i]]++;
        }

        long double k = (long double)total_sum / n;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            freq[a[i]]--;
            long long target = k * (n - 2) - a[i];

            count += freq[target];

            freq[a[i]]++;
        }

        cout << count << endl;
    }

    return 0;
}