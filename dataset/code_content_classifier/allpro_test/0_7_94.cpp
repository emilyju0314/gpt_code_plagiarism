#include <iostream>
#include <vector>

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

        long long max_s = 1;
        for (int i = 1; i < n; i++) {
            max_s = max_s * 10 + 1;
        }

        for (long long s = 1; s <= max_s; s++) {
            int cnt = 0;
            long long value = s;
            for (int i = n - 1; i >= 0; i--) {
                cnt += value / (long long)pow(10, a[i]);
                value %= (long long)pow(10, a[i]);
            }
            if (cnt > k) {
                cout << s << endl;
                break;
            }
        }
    }

    return 0;
}