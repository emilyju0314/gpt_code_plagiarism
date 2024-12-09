#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> wires(n);
    for (int i = 0; i < n; i++) {
        cin >> wires[i];
    }

    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;

        if (x > 1) {
            wires[x-2] += y-1;
        }
        if (x < n) {
            wires[x] += wires[x-1] - y;
        }
        wires[x-1] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << wires[i] << endl;
    }

    return 0;
}