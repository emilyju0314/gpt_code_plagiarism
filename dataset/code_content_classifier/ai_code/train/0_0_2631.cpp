#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<int>> colors(h, vector<int>(w));

    // Read color constraints
    vector<vector<char>> constraints(2 * h - 1, vector<char>(w-1));
    for (int i = 0; i < 2 * h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            cin >> constraints[i][j];
        }
    }

    // The coloring algorithm goes here...

    // Output the result
    cout << "YES" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << colors[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}