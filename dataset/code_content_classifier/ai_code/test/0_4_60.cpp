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

        long double k = (long double)sum / n;
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            long long new_sum = sum - a[i];
            int new_n = n - 1;

            if ((new_sum - k * new_n) % 2 == 0) {
                long long target = (new_sum - k * new_n) / 2;
                cnt += freq[target];
            }
        }

        cout << cnt << endl;
    }

    return 0;
}