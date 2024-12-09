#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    vector<int> distances(n);
    for (int i = 0; i < n; i++) {
        distances[i] = abs(points[i].first - points[(i+1)%n].first) + abs(points[i].second - points[(i+1)%n].second);
    }

    int maxPerimeter = 0;
    for (int k = 3; k <= n; k++) {
        int currentPerimeter = 0;
        for (int i = 0; i < k; i++) {
            currentPerimeter += distances[i];
        }
        maxPerimeter = max(maxPerimeter, currentPerimeter);
    }

    for (int i = 3; i <= n; i++) {
        cout << maxPerimeter << " ";
    }

    return 0;
}