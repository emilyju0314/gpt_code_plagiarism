#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a, int b) {
    return a ^ b;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    // Precompute bitwise XOR values for each pair of elements
    vector<vector<int>> xor_values(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        xor_values[i][i] = a[i];
        for (int j = i + 1; j < n; j++) {
            xor_values[i][j] = f(xor_values[i][j - 1], a[j]);
        }
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; // Convert to 0-based indexing

        // Find maximum value of f for the subarray a[l...r]
        int max_val = 0;
        for (int j = l; j < r; j++) {
            for (int k = j; k < r; k++) {
                max_val = max(max_val, xor_values[j][k]);
            }
        }

        cout << max_val << endl;
    }

    return 0;
}