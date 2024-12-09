#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, k, n, q;
    cin >> x >> k >> n >> q;

    vector<int> jumpCost(k);
    for (int i = 0; i < k; i++) {
        cin >> jumpCost[i];
    }

    vector<pair<int, int>> specialStones;
    for (int i = 0; i < q; i++) {
        int p, wp;
        cin >> p >> wp;
        specialStones.push_back(make_pair(p, wp));
    }

    sort(specialStones.begin(), specialStones.end());

    int energy = 0;
    int stonesCovered = 0;
    for (int i = 0; i < q; i++) {
        energy += jumpCost[stonesCovered % k];
        stonesCovered++;

        energy += specialStones[i].second;
    }

    cout << energy << endl;

    return 0;
}