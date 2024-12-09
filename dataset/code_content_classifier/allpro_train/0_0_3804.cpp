#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Proposal {
    int u, v, w;
    char l;
};

int main() {
    int n, m, k;
    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) {
            break;
        }

        vector<Proposal> proposals(m);
        for (int i = 0; i < m; i++) {
            cin >> proposals[i].u >> proposals[i].v >> proposals[i].w >> proposals[i].l;
        }

        int min_cost = -1;

        for (int bitmask = 0; bitmask < (1 << m); bitmask++) {
            int cnt_a = 0;
            int cnt_b = 0;
            int cost = 0;

            for (int i = 0; i < m; i++) {
                if (bitmask & (1 << i)) {
                    if (proposals[i].l == 'A') {
                        cnt_a++;
                    } else {
                        cnt_b++;
                    }
                    
                    cost += proposals[i].w;
                }
            }

            if (cnt_a == k && cnt_b == n - 1 - k) {
                if (min_cost == -1 || cost < min_cost) {
                    min_cost = cost;
                }
            }
        }

        cout << min_cost << endl;
    }

    return 0;
}