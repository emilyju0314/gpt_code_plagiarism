#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int ans = (n * m) / 2 + (n * m) % 2; // calculate the minimum number of lanterns required
        cout << ans << endl;
    }

    return 0;
}