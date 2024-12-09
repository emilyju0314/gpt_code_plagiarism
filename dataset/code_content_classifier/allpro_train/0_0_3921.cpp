#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double calculateEnergy(vector<pair<int, int>>& miners, vector<pair<int, int>>& mines) {
    sort(miners.begin(), miners.end());
    sort(mines.begin(), mines.end());

    double energy = 0;
    for (int i = 0; i < miners.size(); i++) {
        energy += sqrt(pow(miners[i].first - mines[i].first, 2) + pow(miners[i].second - mines[i].second, 2));
    }

    return energy;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> miners;
        vector<pair<int, int>> mines;

        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) {
                miners.push_back({x, y});
            } else {
                mines.push_back({x, y});
            }
        }

        double result = calculateEnergy(miners, mines);
        cout << fixed << result << endl;
    }

    return 0;
}