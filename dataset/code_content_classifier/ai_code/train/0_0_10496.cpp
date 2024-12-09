#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long diff_x = x2 - x1;
        long long diff_y = y2 - y1;

        long long ans = 1 + diff_x + diff_y + (diff_x * diff_y);

        cout << ans << endl;
    }

    return 0;
}