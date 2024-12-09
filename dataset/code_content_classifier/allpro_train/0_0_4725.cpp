#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int totalChanges = 0;
    for (int i = 0; i < m; i++) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;

        totalChanges += abs(c - f); // calculate absolute difference between capacity and flow
    }

    cout << totalChanges << endl;

    return 0;
}