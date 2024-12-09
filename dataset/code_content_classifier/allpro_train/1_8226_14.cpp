#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cout << setprecision(15) << fixed;
    const double PI = acos(-1);

    double W, H, w, h, x, y;
    cin >> W >> H >> w >> h >> x >> y;

    double left = max(-W / 2, x - w / 2);
    double right = min(W / 2, x + w / 2);
    double top = min(H / 2, y + h / 2);
    double bottom = max(-H / 2, y - h / 2);

    double center_x = (left + right) / 2;
    double center_y = (top + bottom) / 2;
    cout << center_y / center_x << endl;
    return 0;
}
