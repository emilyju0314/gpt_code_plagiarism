#include <iostream>
#include <vector>

using namespace std;

struct Tower {
    vector<int> discs;
    Tower() {}
};

int difficulty(const vector<Tower>& towers) {
    int diff = 0;
    int last = INT32_MAX;
    for (const auto& tower : towers) {
        for (int disc : tower.discs) {
            if (disc < last) {
                diff++;
            }
            last = disc;
        }
    }
    return diff;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Tower> towers(m);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        towers[t-1].discs.push_back(i+1);
    }

    vector<int> result(m-1);

    for (int i = 0; i < m-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        towers[a].discs.insert(towers[a].discs.end(), towers[b].discs.begin(), towers[b].discs.end());
        towers[b].discs.clear();

        result[i] = difficulty(towers);
    }

    for (int r : result) {
        cout << r << endl;
    }

    return 0;
}