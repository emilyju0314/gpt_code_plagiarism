#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = 0, ans = 0;
    int changes = 0;

    while (right < n) {
        if (a[right] <= a[right - 1]) {
            changes++;
        }

        while (changes > 1) {
            if (a[left] <= a[left + 1]) {
                changes--;
            }
            left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }

    cout << ans << endl;

    return 0;
}