#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int ans = 0;
    int l = 0, r = 0;
    while(r < n) {
        while(r < n && a[r] - a[l] <= 5) {
            ans = max(ans, r - l + 1);
            r++;
        }
        l++;
    }

    cout << ans << endl;

    return 0;
}