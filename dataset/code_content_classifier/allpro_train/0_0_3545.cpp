#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        if (sum >= k) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}