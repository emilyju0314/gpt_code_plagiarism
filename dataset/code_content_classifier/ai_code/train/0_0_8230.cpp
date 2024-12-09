#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    long long maxPerimeter = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int next1 = (j + 1) % i;
            int next2 = (j + 2) % i;
            long long side1 = abs(points[j].first - points[next1].first) + abs(points[j].second - points[next1].second);
            long long side2 = abs(points[next1].first - points[next2].first) + abs(points[next1].second - points[next2].second);
            
            long long perimeter = side1 + side2;
            for (int k = 0; k < n; k++) {
                if (k == j || k == next1 || k == next2) continue;
                long long curDist = abs(points[next2].first - points[k].first) + abs(points[next2].second - points[k].second);
                perimeter = max(perimeter, side1 + curDist);
            }
            
            maxPerimeter = max(maxPerimeter, perimeter);
        }

        cout << maxPerimeter << " ";
    }

    return 0;
}