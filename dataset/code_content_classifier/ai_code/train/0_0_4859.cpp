#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;

        int teams = min(min(c, m), (c + m + x) / 3);
        cout << teams << endl;
    }

    return 0;
}