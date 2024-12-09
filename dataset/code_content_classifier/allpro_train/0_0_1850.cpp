#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int maxDist = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            maxDist = max(maxDist, abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second));
        }
    }

    cout << fixed;
    cout.precision(15);
    cout << maxDist / 2.0 << endl;

    return 0;
}