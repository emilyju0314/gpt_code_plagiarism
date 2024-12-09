#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    unordered_set<int> blockedCells;
    for (int k = 0; k < q; k++) {
        int ki;
        cin >> ki;

        blockedCells.clear();
        for (int i = 0; i < ki; i++) {
            int ri, ci;
            cin >> ri >> ci;
            blockedCells.insert((ri-1) * w + (ci-1));
        }

        bool interesting = true;
        int start = 0, end = h * w - 1;
        while (start != end) {
            if (blockedCells.count(start) && blockedCells.count(end)) {
                interesting = false;
                break;
            }
            if (blockedCells.count(start)) {
                start++;
            } else if (blockedCells.count(end)) {
                end--;
            } else {
                start++;
                end--;
            }
        }
        
        if (interesting) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cout.flush();
    }

    return 0;
}