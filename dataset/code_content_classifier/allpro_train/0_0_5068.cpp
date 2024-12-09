#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> contamination(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            contamination[i][j] = c - '0';
        }
    }

    bool possible = false;

    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < N; y1++) {
            for (int x2 = x1 + 1; x2 < N; x2++) {
                for (int y2 = y1 + 1; y2 < N; y2++) {
                    int corners = 0;
                    for (int i = x1; i <= x2; i++) {
                        for (int j = y1; j <= y2; j++) {
                            if ((i == x1 || i == x2) && (j == y1 || j == y2)) {
                                corners += contamination[i][j];
                            }
                        }
                    }
                    if (corners == 1 && x2 - x1 == y2 - y1) {
                        possible = true;
                    }
                }
            }
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}