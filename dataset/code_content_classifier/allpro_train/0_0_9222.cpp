#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> chocolate(n + 1, vector<int>(n + 1, 0));
    map<pair<int, int>, int> eaten_pieces;

    for (int i = 1; i <= q; i++) {
        int x, y;
        char direction;
        cin >> x >> y >> direction;

        int eaten = 0;
        if (direction == 'U') {
            for (int r = y; r >= 1; r--) {
                if (eaten_pieces[{x, r}] != 0) {
                    break;
                }
                chocolate[x][r] = i;
                eaten++;
            }
        } else if (direction == 'L') {
            for (int c = x; c >= 1; c--) {
                if (eaten_pieces[{c, y}] != 0) {
                    break;
                }
                chocolate[c][y] = i;
                eaten++;
            }
        }

        cout << eaten << endl;
    }

    return 0;
}