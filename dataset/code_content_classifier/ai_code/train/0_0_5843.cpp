#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> centers;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        centers.push_back(make_pair((x1 + x2) / 2, (y1 + y2) / 2));
    }

    sort(centers.begin(), centers.end());

    long long minX = 1, minY = 1, maxX = 1000000000, maxY = 1000000000;

    for (int i = 0; i+k < n; i++) {
        long long diffX = centers[i+k].first - centers[i].first;
        long long diffY = centers[i+k].second - centers[i].second;

        if (diffX > 0) {
            maxX = min(maxX, (diffX + 1) / 2);
        } else {
            minX = max(minX, (diffX - 1) / 2);
        }

        if (diffY > 0) {
            maxY = min(maxY, (diffY + 1) / 2);
        } else {
            minY = max(minY, (diffY - 1) / 2);
        }
    }

    long long width = max(0LL, maxX - minX + 1);
    long long height = max(0LL, maxY - minY + 1);

    cout << width * height << endl;

    return 0;
}