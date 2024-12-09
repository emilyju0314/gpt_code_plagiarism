#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    double result = 0;
    for (int i = 0; i < N; i++) {
        if (i != K - 1) {
            result += distance(points[K-1], points[i]);
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << result << endl;

    return 0;
}