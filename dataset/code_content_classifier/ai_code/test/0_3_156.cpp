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
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = a[i];
            sum += a[i];
        }

        long long steps = 0;
        sort(diff.begin(), diff.end(), greater<int>());
        for (int i = 0; i < n && sum > k; i++) {
            sum -= diff[i];
            steps++;
        }

        cout << steps << endl;
    }

    return 0;
}