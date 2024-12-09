#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> potatoes;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        potatoes.push_back({x, y});
    }

    sort(potatoes.begin(), potatoes.end());

    int energy = 0;
    int maxX = 0, maxY = 0;
    for (auto p : potatoes) {
        int x = p.first, y = p.second;
        energy += max(abs(x - maxX), abs(y - maxY));
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    cout << energy << endl;

    return 0;
}