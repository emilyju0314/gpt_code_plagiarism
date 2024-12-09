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

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long steps = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum > k) {
                steps += (sum - k);
                sum = k;
            }
        }

        cout << steps << endl;
    }

    return 0;
}