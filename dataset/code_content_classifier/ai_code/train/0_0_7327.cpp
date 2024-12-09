#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> souvenirsGiven(n, 0);
    vector<pair<int, int>> pairs;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pairs.push_back({x, y});
        souvenirsGiven[y-1]++;
    }

    int maxSouvenirs = *max_element(souvenirsGiven.begin(), souvenirsGiven.end());

    cout << maxSouvenirs << endl;

    for(auto pair : pairs) {
        int giver = pair.second;
        int receiver = pair.first;

        if(souvenirsGiven[giver-1] == maxSouvenirs) {
            swap(giver, receiver);
        }

        cout << giver << " " << receiver << endl;
    }

    return 0;
}