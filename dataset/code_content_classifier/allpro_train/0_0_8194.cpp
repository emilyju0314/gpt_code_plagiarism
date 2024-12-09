#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Connect exit nodes to form the backbone
    cout << (n - 1) / k << endl;
    int curr_node = 2;
    for (int i = 1; i <= k; i++) {
        int num_connections = (n - 1) / k;
        for (int j = 0; j < num_connections; j++) {
            cout << i << " " << curr_node << endl;
            curr_node++;
            if (curr_node > n) {
                curr_node = 2;
            }
        }
    }

    // Connect remaining nodes to the backbone
    for (int i = curr_node; i <= n; i++) {
        cout << i << " 1" << endl;
    }

    return 0;
}