#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = 1;
        int prev_sum = arr[0];
        int max_val = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > max_val) {
                ans++;
                max_val = arr[i];
            }

            prev_sum += arr[i];
        }

        cout << ans << endl;
    }

    return 0;
}