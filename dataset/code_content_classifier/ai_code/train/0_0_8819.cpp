#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, L, P;
    cin >> H >> W >> L >> P;

    set<pair<int, int>> noWall;
    for (int i = 0; i < P; i++) {
        int row, col;
        cin >> row >> col;
        noWall.insert({row, col});
    }

    long long count = 0;
    for (int size = L; size <= min(H, W); size++) {
        for (int i = 0; i <= H - size; i++) {
            for (int j = 0; j <= W - size; j++) {
                bool valid = true;
                for (int k = 0; k < size; k++) {
                    if (noWall.count({i + k + 1, j + 1}) || noWall.count({i + k + 1, j + size}) ||
                        noWall.count({i + 1, j + k + 1}) || noWall.count({i + size, j + k + 1})) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}