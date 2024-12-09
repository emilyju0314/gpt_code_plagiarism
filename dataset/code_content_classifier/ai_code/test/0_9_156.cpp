#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if(sum <= k) {
            cout << "0" << endl;
            continue;
        }

        sort(a.begin(), a.end());

        long long prefixSum = 0;
        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            prefixSum += a[i];
            if(sum - prefixSum <= k) {
                ans = n - i - 1;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}