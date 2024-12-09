#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c = (k + 1) / 2;
    cout << c << endl;

    // Create a valid edge coloring
    vector<int> colors;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int color = (i + j) % c + 1;
            colors.push_back(color);
        }
    }

    // Output the edge colors
    for(int color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}