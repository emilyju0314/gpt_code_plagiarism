#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    bool reachable = false;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a <= 0 && b >= m) {
            reachable = true;
        }
    }

    if (reachable) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}