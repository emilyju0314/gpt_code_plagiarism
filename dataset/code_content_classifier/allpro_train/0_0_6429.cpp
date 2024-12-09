#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> cake(H);
    for (int i = 0; i < H; i++) {
        cin >> cake[i];
    }

    int berries = 0;
    int x = 0, y = 0;

    while (x < H && y < W) {
        if (cake[x][y] == '*') {
            berries++;
        }
        if (x + 1 < H && y + 1 < W) {
            if (cake[x + 1][y] == '*' && cake[x][y + 1] == '*') {
                if (cake[x + 1][y + 1] == '*') {
                    if (x + 2 < H && y + 2 < W) {
                        if (cake[x + 2][y + 1] == '*' && cake[x + 1][y + 2] == '*') {
                            y += 2;
                        } else {
                            x += 2;
                        }
                    } else {
                        x += 2;
                    }
                } else {
                    x++;
                }
            } else if (cake[x + 1][y] == '*') {
                x++;
            } else if (cake[x][y + 1] == '*') {
                y++;
            } else {
                break;
            }
        } else if (x + 1 < H) {
            x++;
        } else if (y + 1 < W) {
            y++;
        } else {
            break;
        }
    }

    cout << berries << endl;

    return 0;
}