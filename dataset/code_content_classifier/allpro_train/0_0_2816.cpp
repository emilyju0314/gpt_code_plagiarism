#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> pixels(n, vector<char>(m));
    bool colored = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pixels[i][j];
            if (pixels[i][j] == 'C' || pixels[i][j] == 'M' || pixels[i][j] == 'Y') {
                colored = true;
            }
        }
    }

    if (colored) {
        cout << "#Color" << endl;
    } else {
        cout << "#Black&White" << endl;
    }

    return 0;
}