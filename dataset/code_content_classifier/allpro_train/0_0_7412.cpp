#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << k << endl;

    // Connect the exit-nodes in a chain
    for (int i = 1; i <= k; i++) {
        cout << i << " " << i + 1 << endl;
    }

    // Connect the remaining nodes to the exit-nodes
    for (int i = k + 1; i < n; i++) {
        cout << k << " " << i + 1 << endl;
    }

    return 0;
}