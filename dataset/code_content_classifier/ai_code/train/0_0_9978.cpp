#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> program(m);
    for (int i = 0; i < m; i++) {
        cin >> program[i];
    }

    int bp_x = 0, bp_y = 0;
    int dp_x = 1, dp_y = 0;
    int cp_x = 0, cp_y = -1;

    for (int i = 0; i < n; i++) {
        // Finding the current color block
        char current_color = program[bp_y][bp_x];

        // Moving towards the edge in the direction of DP
        while (bp_x + dp_x >= 0 && bp_x + dp_x < program[0].size() &&
                bp_y + dp_y >= 0 && bp_y + dp_y < m &&
                program[bp_y + dp_y][bp_x + dp_x] == current_color) {
            bp_x += dp_x;
            bp_y += dp_y;
        }

        // Finding the furthest block in the direction of CP
        char furthest_color = current_color;
        int px = bp_x, py = bp_y;
        while (px >= 0 && px < program[0].size() && py >= 0 && py < m) {
            if (program[py][px] != current_color) {
                break;
            }
            furthest_color = current_color;
            px += cp_x;
            py += cp_y;
        }

        // Moving to the next pixel
        if (px < 0 || px >= program[0].size() || py < 0 || py >= m || program[py][px] != current_color) {
            if (cp_x == 0) {
                cp_x = dp_y;
                cp_y = -dp_x;
            } else {
                cp_x = -dp_y;
                cp_y = dp_x;
                int temp = dp_x;
                dp_x = cp_x;
                cp_x = temp;
                temp = dp_y;
                dp_y = cp_y;
                cp_y = temp;
            }
        } else {
            bp_x = px;
            bp_y = py;
        }
    }

    cout << program[bp_y][bp_x] << endl;

    return 0;
}