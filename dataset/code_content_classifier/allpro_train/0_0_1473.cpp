#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int W;
    cin >> W;

    vector<string> initial(2);
    vector<string> target(2);

    for (int i = 0; i < 2; i++) {
        cin >> initial[i];
    }

    cin.ignore(); // Ignore the empty line

    for (int i = 0; i < 2; i++) {
        cin >> target[i];
    }

    int count = 0;

    for (int i = 0; i < W - 1; i++) {
        if (initial[0][i] != target[0][i]) {
            // Perform square rotation
            count++;
            initial[0][i] = (initial[0][i] == 'o') ? '.' : 'o';
            initial[0][i+1] = (initial[0][i+1] == 'o') ? '.' : 'o';
            initial[1][i] = (initial[1][i] == 'o') ? '.' : 'o';
            initial[1][i+1] = (initial[1][i+1] == 'o') ? '.' : 'o';
        }

        if (initial[1][i] != target[1][i]) {
            // Perform square rotation
            count++;
            initial[0][i] = (initial[0][i] == 'o') ? '.' : 'o';
            initial[1][i] = (initial[1][i] == 'o') ? '.' : 'o';
            initial[0][i+1] = (initial[0][i+1] == 'o') ? '.' : 'o';
            initial[1][i+1] = (initial[1][i+1] == 'o') ? '.' : 'o';
        }
    }

    if (initial[0][W-1] != target[0][W-1]) {
        count++;
        initial[0][W-1] = (initial[0][W-1] == 'o') ? '.' : 'o';
        initial[1][W-1] = (initial[1][W-1] == 'o') ? '.' : 'o';
    }

    if (initial[1][W-1] != target[1][W-1]) {
        count++;
        initial[0][W-1] = (initial[0][W-1] == 'o') ? '.' : 'o';
        initial[1][W-1] = (initial[1][W-1] == 'o') ? '.' : 'o';
    }

    cout << count << endl;

    return 0;
}