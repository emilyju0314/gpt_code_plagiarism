#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = 0, zeros = 0, ans = 0, best_left = 0;

    while (right < n) {
        if (a[right] == 0) {
            zeros++;
        }
        while (zeros > k) {
            if (a[left] == 0) {
                zeros--;
            }
            left++;
        }
        if (right - left + 1 > ans) {
            ans = right - left + 1;
            best_left = left;
        }
        right++;
    }

    cout << ans << "\n";
    for (int i = best_left; i < best_left + ans; i++) {
        a[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}