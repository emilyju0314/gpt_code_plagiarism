#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> beads(n);
    for (int i = 0; i < n; i++) {
        cin >> beads[i];
    }

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;
            beads[p-1] = x;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;

            int memory = 0;
            for (int j = 0; j < n; j++) {
                if (beads[j] >= l && beads[j] <= r) {
                    int first_pos = find(beads.begin(), beads.end(), beads[j]) - beads.begin() + 1;
                    int last_pos = j + 1;
                    memory += (last_pos - first_pos);
                    beads[j] = 0;
                }
            }

            cout << memory << endl;
        }
    }

    return 0;
}