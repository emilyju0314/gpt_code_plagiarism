#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<pair<int, int>> blocks;
        for (int i = 1; i <= n; i++) {
            int h;
            cin >> h;
            blocks.push_back({h, i});
        }

        sort(blocks.begin(), blocks.end());

        vector<int> towerHeight(m, 0);
        vector<int> towerIndex(n);

        for (int i = 0; i < n; i++) {
            int minHeight = *min_element(towerHeight.begin(), towerHeight.end());
            int index = min_element(towerHeight.begin(), towerHeight.end()) - towerHeight.begin();
            towerHeight[index] += blocks[i].first;
            towerIndex[blocks[i].second - 1] = index + 1;
        }

        int maxHeight = *max_element(towerHeight.begin(), towerHeight.end());
        if (maxHeight - *min_element(towerHeight.begin(), towerHeight.end()) > x) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << towerIndex[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}