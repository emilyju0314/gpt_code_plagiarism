#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double sumPerimeter = 0;
    for (int i = 0; i < N; i++) {
        pair<int, int> p1 = points[i];
        pair<int, int> p2 = points[(i + 1) % N]; // Wrap around to connect the last and first points

        double dist = distance(p1.first, p1.second, p2.first, p2.second);
        sumPerimeter += 2 * M_PI * dist;
    }

    cout << fixed << setprecision(9) << sumPerimeter << endl;

    return 0;
}