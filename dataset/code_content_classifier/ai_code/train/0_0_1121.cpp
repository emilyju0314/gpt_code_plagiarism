#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w, h;
char rails[6][6];

bool isValidLayout() {
    // Implement the logic to check if the layout is valid
    // Return true if all rail ends are connected, false otherwise
}

int calculateFunTime() {
    // Implement the logic to calculate the fun time of a layout
}

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> rails[i][j];
            }
        }

        vector<int> perm(w*h, 0);
        for (int i = 0; i < 3*h*w; i++) {
            perm[i] = i;
        }

        int maxFunTime = 0;
        do {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    int index = i*w + j;
                    int rotation = perm[index] % 4;
                    // Rotate the rail unit
                }
            }

            if (isValidLayout()) {
                maxFunTime = max(maxFunTime, calculateFunTime());
            }
        } while (next_permutation(perm.begin(), perm.end()));

        cout << maxFunTime << endl;
    }

    return 0;
}