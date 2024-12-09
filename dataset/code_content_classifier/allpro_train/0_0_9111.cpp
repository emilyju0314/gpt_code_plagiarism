#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;

        int min_common = min(z1, y2);
        z1 -= min_common;
        y2 -= min_common;

        int max_score = min(z1, z2) * 2;
        z1 -= min(z1, z2);
        z2 -= min(z2, z1);

        int common = min(y1, y2);
        y1 -= common;
        y2 -= common;

        int min_score = -2 * min(y1, x2);
        
        cout << max_score + min_score << "\n";
    }

    return 0;
}