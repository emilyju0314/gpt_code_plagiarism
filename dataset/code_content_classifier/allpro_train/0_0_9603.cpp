#include <iostream>
#include <vector>
using namespace std;

bool checkPiece(const vector<string>& puzzle, const vector<string>& piece, int x, int y) {
    int h = piece.size();
    int w = piece[0].size();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (y + i >= puzzle.size() || x + j >= puzzle[0].size()) {
                return false;
            }
            
            if (piece[i][j] == '#' && puzzle[y + i][x + j] != '.') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int H, W;
    while (cin >> H >> W && H && W) {
        vector<string> puzzle(H);
        for (int i = 0; i < H; i++) {
            cin >> puzzle[i];
        }

        int n;
        cin >> n;

        vector<vector<string>> pieces(n);
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            pieces[i].resize(h);
            for (int j = 0; j < h; j++) {
                cin >> pieces[i][j];
            }
        }

        int p;
        cin >> p;

        for (int i = 0; i < p; i++) {
            int k;
            cin >> k;
            bool valid = false;
            
            for (int j = 0; j < k; j++) {
                int t, x, y;
                cin >> t >> x >> y;
                
                if (checkPiece(puzzle, pieces[t-1], x-1, y-1)) {
                    valid = true;
                }
            }

            if (valid) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}