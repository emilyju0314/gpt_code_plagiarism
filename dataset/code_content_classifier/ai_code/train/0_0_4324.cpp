#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i-x1)*(y2-y1) == (j-y1)*(x2-x1)) {
                continue;
            }
            if ((i + j <= x1 + y1 + x2 + y2) && (i + x1 >= max(x2, x1))
                    && (i + y1 >= max(y2, y1))) {
                ans++;
            }
        }
    }

    cout << abs(ans) << endl;

    return 0;
}