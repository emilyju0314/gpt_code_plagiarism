#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        long long ans = max(1LL * arr[0] * arr[1] * arr[n-1] * arr[n-2] * arr[n-3], 1LL * arr[n-5] * arr[n-4] * arr[n-1] * arr[n-2] * arr[n-3]);
        cout << ans << endl;
    }

    return 0;
}