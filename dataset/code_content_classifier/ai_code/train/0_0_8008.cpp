#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Check if it's possible to form k islands
    int max_islands = (n * n + 1) / 2;
    if (k > max_islands) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    bool is_sand = true; // Start with covering cell with sand
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if we need to cover cell with sand
            if (k > 0 && is_sand) {
                cout << 'L';
                k--;
            } else {
                cout << 'S';
            }
            is_sand = !is_sand;
        }
        cout << endl;
    }

    return 0;
}