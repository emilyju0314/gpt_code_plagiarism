#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int dr[] = {1, -1, 0, 0, 0};
int dc[] = {0, 0, 1, -1, 0};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        set<tuple<int, int, int>> obstacles;
        int r, c;
        for (int i = 0; i < k; i++) {
            cin >> r >> c;
            obstacles.insert(make_tuple(r, c, 0));
        }

        int sr, sc, tr, tc;
        cin >> sr >> sc >> tr >> tc;

        queue<tuple<int, int, int>> q;
        q.push(make_tuple(sr, sc, 0));

        int min_steps = -1;
        set<tuple<int, int, int>> visited;
        visited.insert(make_tuple(sr, sc, 0));

        while (!q.empty()) {
            int cr, cc, steps;
            tie(cr, cc, steps) = q.front();
            q.pop();

            if (cr == tr && cc == tc) {
                min_steps = steps;
                break;
            }

            // Expand neighbors
            for (int i = 0; i < 5; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                int nsteps = steps + 1;

                if (nr < 1 || nc < 1 || nr > n || nc > m) {
                    continue;
                }

                if (obstacles.count(make_tuple(nr, nc, 0))) {
                    continue;
                }

                if (visited.count(make_tuple(nr, nc, 0))) {
                    continue;
                }

                q.push(make_tuple(nr, nc, nsteps));
                visited.insert(make_tuple(nr, nc, 0));
            }
        }

        cout << min_steps << endl;
    }

    return 0;
}
