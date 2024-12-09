#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    while (cin >> n >> c) {
        if (n == 0 && c == 0) break;

        vector<vector<int>> beatMap(n, vector<int>(16));
        vector<vector<int>> pressMap(c, vector<int>(16));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 16; j++) {
                cin >> beatMap[i][j];
            }
        }

        for (int i = 0; i < c; i++) {
            for (int j = 0; j < 16; j++) {
                cin >> pressMap[i][j];
            }
        }

        int maxScore = 0;
        for (int mask = 0; mask < (1 << c); mask++) {
            vector<int> buttonPressed(16, 0);
            int score = 0;

            // Simulate the button presses based on the mask
            for (int i = 0; i < c; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < 16; j++) {
                        if (pressMap[i][j]) {
                            buttonPressed[j] = 1;
                        }
                    }
                }
            }

            // Calculate the score based on the button press and light up
            for (int i = 0; i < n; i++) {
                int countLit = 0;
                for (int j = 0; j < 16; j++) {
                    if (beatMap[i][j] && buttonPressed[j]) {
                        countLit++;
                    }
                }
                score += countLit;
            }

            maxScore = max(maxScore, score);
        }

        cout << maxScore << endl;
    }

    return 0;
}