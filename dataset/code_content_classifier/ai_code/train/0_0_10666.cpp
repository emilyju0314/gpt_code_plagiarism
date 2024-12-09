#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int min_place = max(1, min(x, y) + 1 - n + max(1, x + y - n));
        int max_place = min(n, x + y - 1);

        cout << min_place << " " << max_place << endl;
    }

    return 0;
}