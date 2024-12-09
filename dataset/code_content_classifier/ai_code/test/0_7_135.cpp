#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        for(int i = 0; i < k+1; i++) {
            ans = max(ans, arr[n-1-i]);
        }

        cout << ans << endl;
    }

    return 0;
}