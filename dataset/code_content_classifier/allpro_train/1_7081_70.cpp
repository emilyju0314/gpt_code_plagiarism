#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int k = *max_element(a, a+n), l = *min_element(a, a+n);
    if (k - l >= 2) { cout << "No\n"; return  0; }
    if (k == l) {
        cout << (k == n-1 || n/2 >= k ? "Yes\n" : "No\n");
        return 0;
    }
    int x = 0;
    for (int b : a) if (b == k-1) x++;
    cout << (x <= k-1 && n-x >= 2 * (k-x) ? "Yes\n" : "No\n");
}
