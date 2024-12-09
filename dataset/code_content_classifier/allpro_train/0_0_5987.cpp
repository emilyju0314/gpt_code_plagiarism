#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int left = x;
        int right = a - x - 1;
        int top = y;
        int bottom = b - y - 1;

        cout << max(max(left, right) * b, max(top, bottom) * a) << endl;
    }

    return 0;
}