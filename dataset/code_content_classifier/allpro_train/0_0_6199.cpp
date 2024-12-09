#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    bool valid = true;
    // Check if each stripe has a distinct color
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
           if (field[i][j] != field[i][0]) {
               valid = false;
               break;
           }
        }
        if (!valid) {
            break;
        }
    }

    // Check if each color is used exactly once in the flag
    bool red = false, green = false, blue = false;
    for (int i = 0; i < n; i++) {
        if (field[i][0] == 'R') {
            red = true;
        } else if (field[i][0] == 'G') {
            green = true;
        } else if (field[i][0] == 'B') {
            blue = true;
        }
    }

    if (valid && red && green && blue) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}