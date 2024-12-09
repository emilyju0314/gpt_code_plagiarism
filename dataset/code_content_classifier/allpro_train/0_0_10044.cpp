#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, N;

    while (true) {
        cin >> H >> N;

        if (H == 0 && N == 0) {
            break;
        }

        vector<vector<char>> initial_state(H, vector<char>(4, '.'));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> initial_state[i][j];
            }
        }

        int total_erased = 0;

        for (int i = 0; i < N; i++) {
            vector<vector<char>> lump(4, vector<char>(2));

            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 2; k++) {
                    cin >> lump[j][k];
                }
            }

            // Check for complete lines in initial state
            for (int j = 0; j < H; j++) {
                if (initial_state[j][0] == '#' && initial_state[j][1] == '#' && initial_state[j][2] == '#' && initial_state[j][3] == '#') {
                    total_erased++;
                    initial_state[j][0] = initial_state[j][1] = initial_state[j][2] = initial_state[j][3] = '.';
                }
            }

            // Check for matching blocks in lump
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 2; k++) {
                    if (j < 2 && k < 2 && lump[j][k] == '#' && initial_state[j][k] == '#') {
                        total_erased++;
                        initial_state[j][k] = '.';
                    }
                }
            }
        }

        cout << total_erased << endl;
    }

    return 0;
}