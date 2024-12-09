#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool canAttack(Point a, Point b) {
    return a.x == b.x || a.y == b.y;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Point> rooks(M);
    vector<int> attacks(M, 0);

    for (int i = 0; i < M; i++) {
        cin >> rooks[i].x >> rooks[i].y;
        for (int j = 0; j < i; j++) {
            if (canAttack(rooks[i], rooks[j])) {
                attacks[i]++;
                attacks[j]++;
            }
        }
    }

    int minCaptured = *max_element(attacks.begin(), attacks.end());
    int maxCaptured = 0;
    for (int i = 0; i < M; i++) {
        maxCaptured += attacks[i] / 2;
    }

    cout << minCaptured << " " << maxCaptured << endl;

    return 0;
}