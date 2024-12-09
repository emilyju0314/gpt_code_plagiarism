#include <iostream>
#include <string>

using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    string ans = "";

    while (x != 1 && y != 1) {
        if (x > y) {
            long long cnt = x / y;
            ans += to_string(cnt) + 'A';
            x %= y;
        } else {
            long long cnt = y / x;
            ans += to_string(cnt) + 'B';
            y %= x;
        }
    }

    if (x == 1 && y == 0) {
        ans += 'A';
    } else if (y == 1 && x == 0) {
        ans += 'B';
    } else {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}