#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int antiDiagonal = 0;
    map<int, int> eatenPieces;

    for (int i = 0; i < q; i++) {
        int x, y;
        char direction;
        cin >> x >> y >> direction;

        int pieces = 0;

        if (direction == 'U') {
            pieces = min(x, y) + antiDiagonal - eatenPieces[y];
        } else if (direction == 'L') {
            pieces = min(x, y) + antiDiagonal - eatenPieces[x];
        }

        eatenPieces[min(x, y)] = max(eatenPieces[min(x, y)], min(x, y) + 1);

        cout << pieces << endl;

        antiDiagonal = max(antiDiagonal, min(x, y) + 1);
    }

    return 0;
}