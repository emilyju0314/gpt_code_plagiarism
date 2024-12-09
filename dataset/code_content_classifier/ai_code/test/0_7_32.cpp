#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> prefSum(n);
        prefSum[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + a[i];
        }

        int ans = 1;
        int currLen = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (prefSum[i] < prefSum[i + 1]) {
                currLen++;
                ans = max(ans, currLen);
            } else {
                currLen = 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}