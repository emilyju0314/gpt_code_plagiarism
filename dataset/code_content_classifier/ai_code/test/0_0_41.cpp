#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Calculate the minimum number of colors needed
    int c = min(k - 1, n - k);

    // Output the minimum number of colors
    cout << c + 1 << endl;

    // Output the valid edge coloring
    vector<int> colors((n * (n - 1)) / 2 + 1, 1);
    for (int i = 1; i < k; i++) {
        for (int j = i + 1; j <= k; j++) {
            colors[(i-1) * n - (i-1) * i / 2 + j - i] = i;
        }
    }
    int color = k;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (colors[(i-1) * n - (i-1) * i / 2 + j - i] == 1) {
                colors[(i-1) * n - (i-1) * i / 2 + j - i] = color;
            }
        }
    }

    for (int i = 1; i <= n * (n - 1) / 2; i++) {
        cout << colors[i] << " ";
    }
    
    return 0;
}