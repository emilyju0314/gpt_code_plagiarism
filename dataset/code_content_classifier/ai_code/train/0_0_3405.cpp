#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;

    int field[1011][1011];
    memset(field, 0, sizeof(field));

    int x = 505, y = 505; // starting position at the center of the field bed
    field[x][y] = 1; // mark the starting bed as sprayed

    for (int i = 0; i < n; i++) {
        char dir;
        int dist;
        cin >> dir >> dist;

        if (dir == 'L') {
            for (int j = 0; j < dist; j++) {
                field[x][--y] = 1;
            }
        } else if (dir == 'R') {
            for (int j = 0; j < dist; j++) {
                field[x][++y] = 1;
            }
        } else if (dir == 'U') {
            for (int j = 0; j < dist; j++) {
                field[--x][y] = 1;
            }
        } else if (dir == 'D') {
            for (int j = 0; j < dist; j++) {
                field[++x][y] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= 1010; i++) {
        for (int j = 1; j <= 1010; j++) {
            if (field[i][j] == 0 && (field[i-1][j] == 1 || field[i+1][j] == 1 || field[i][j-1] == 1 || field[i][j+1] == 1)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}