#include <iostream>
#include <vector>

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
        int min_steps = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > k) {
                min_steps += (sum - k);
                sum = k;
            }
        }

        cout << min_steps << endl;
    }

    return 0;
}