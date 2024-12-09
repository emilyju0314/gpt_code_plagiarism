#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    while (cin >> m) {
        if (m == 0) {
            break;
        }

        vector<int> piles(m, 1);
        vector<int> cubes(m, -1);
        for (int i = 0; i < m; i++) {
            cubes[i] = i;
        }

        int a, b;
        while (cin >> a >> b) {
            if (a == 0 && b == 0) {
                break;
            }

            a--;
            b--;

            if (a == b || cubes[a] == cubes[b]) {
                continue;
            }

            int height_a = piles[cubes[a]];
            int height_b = (b == -1 ? 0 : piles[cubes[b]]);
            piles[cubes[b]] += height_a;
            piles[cubes[a]] = height_b;

            int cube_to_move = cubes[a];
            for (int i = 0; i < m; i++) {
                if (cubes[i] == cube_to_move) {
                    cubes[i] = cubes[b];
                }
            }
        }

        vector<int> heights;
        for (int i = 0; i < m; i++) {
            if (piles[i] > 0) {
                heights.push_back(piles[i]);
            }
        }

        for (int height : heights) {
            cout << height << endl;
        }
        cout << "end" << endl;
    }

    return 0;
}