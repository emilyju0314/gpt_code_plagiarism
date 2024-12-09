#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int left = a - b;
        int down = c - d;

        if ((x + left >= x1 && x + left <= x2 && y + down >= y1 && y + down <= y2) && (x1 < x2 || a + b == 0) && (y1 < y2 || c + d == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    
    }

    return 0;
}