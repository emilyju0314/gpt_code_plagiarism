#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    // Handle the case when either H or W is even
    if (H % 2 == 0 || W % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Find the minimum possible value of Smax - Smin
    int ans = min(H, W) - 1;
    ans += (max(H, W) + 1) / 2 - 1;

    cout << ans << endl;

    return 0;
}