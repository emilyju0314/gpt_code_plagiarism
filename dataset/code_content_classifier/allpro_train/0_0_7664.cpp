#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> logo(3);
    for (int i = 0; i < 3; i++) {
        cin >> logo[i];
    }

    sort(logo.begin(), logo.end());

    int side = max(logo[2], logo[0] + logo[1]);
    if (side < logo[0] + logo[1] + logo[2]) {
        side = logo[0] + logo[1] + logo[2];
    }

    cout << side << endl;
    vector<vector<char>> billboard(side, vector<char>(side, '.'));

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (i < logo[0]) {
                if (j < logo[0]) {
                    billboard[i][j] = 'A';
                } else if (j >= logo[0] && j < logo[0] + logo[1]) {
                    billboard[i][j] = 'B';
                } else if (j >= logo[0] + logo[1]) {
                    billboard[i][j] = 'C';
                }
            } else if (i >= logo[0] && i < logo[0] + logo[1]) {
                if (j < logo[0]) {
                    billboard[i][j] = 'B';
                } else if (j >= logo[0] && j < logo[0] + logo[1]) {
                    billboard[i][j] = 'B';
                } else if (j >= logo[0] + logo[1]) {
                    billboard[i][j] = 'C';
                }
            } else if (i >= logo[0] + logo[1]) {
                if (j < logo[0]) {
                    billboard[i][j] = 'C';
                } else if (j >= logo[0] && j < logo[0] + logo[1]) {
                    billboard[i][j] = 'C';
                } else if (j >= logo[0] + logo[1]) {
                    billboard[i][j] = 'C';
                }
            }
        }
    }

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << billboard[i][j];
        }
        cout << endl;
    }

    return 0;
}