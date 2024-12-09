#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            ans += (i - start) * (n - i);
            start = i;
        }
    }

    ans += n; // Counting subarrays of size 1

    cout << ans << endl;

    return 0;
}