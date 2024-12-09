#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> lamps;
    unordered_map<int, int> temperatureSum;

    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        lamps.push_back({a, t});
        temperatureSum[a] += t;
    }

    int sum = temperatureSum[lamps[0].first];
    for (int i = 0; i < n; i++) {
        if (temperatureSum[lamps[i].first] != sum) {
            cout << lamps[0].first << " " << lamps[i].first << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}