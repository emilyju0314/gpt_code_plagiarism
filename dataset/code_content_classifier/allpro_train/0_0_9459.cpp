#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long u, v;
    cin >> u >> v;

    if((u > v) || ((v - u) % 2 != 0)) {
        cout << -1 << endl;
        return 0;
    }

    if(u == 0 && v == 0) {
        cout << 0 << endl;
        return 0;
    }

    if(u == v) {
        cout << 1 << endl;
        cout << u << endl;
        return 0;
    }

    long long x = (v - u) / 2;
    if((x & u) != 0) {
        cout << 3 << endl;
        cout << u << " " << x << " " << x << endl;
    } else {
        cout << 2 << endl;
        cout << (u ^ x) << " " << x << endl;
    }

    return 0;
}