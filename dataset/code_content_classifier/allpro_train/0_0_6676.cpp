#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> picture(h);
    for (int i = 0; i < h; i++) {
        cin >> picture[i];
    }

    bool valid = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (picture[i][j] == '*') {
                // Check if '+' shape
                bool up = false, down = false, left = false, right = false;

                // Check up
                for (int k = i - 1; k >= 0; k--) {
                    if (picture[k][j] == '*') {
                        up = true;
                    } else {
                        break;
                    }
                }

                // Check down
                for (int k = i + 1; k < h; k++) {
                    if (picture[k][j] == '*') {
                        down = true;
                    } else {
                        break;
                    }
                }

                // Check left
                for (int k = j - 1; k >= 0; k--) {
                    if (picture[i][k] == '*') {
                        left = true;
                    } else {
                        break;
                    }
                }

                // Check right
                for (int k = j + 1; k < w; k++) {
                    if (picture[i][k] == '*') {
                        right = true;
                    } else {
                        break;
                    }
                }

                if (up && down && left && right) {
                    valid = true;
                    break;
                }
            }
        }
        if (valid) {
            break;
        }
    }

    if (valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}