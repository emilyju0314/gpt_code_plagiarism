#include <iostream>
using namespace std;

bool canTravel(int u, int v) {
    return (u & v) == v;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        if (canTravel(u, v)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}