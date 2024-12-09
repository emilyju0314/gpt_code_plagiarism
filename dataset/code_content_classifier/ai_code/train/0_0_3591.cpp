#include <iostream>
#include <vector>

using namespace std;

struct Road {
    int a, b, c;
};

bool isOnSameSide(int x, int y, const Road& road) {
    return road.a * x + road.b * y + road.c > 0;
}

int main() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    vector<Road> roads(n);
    for (int i = 0; i < n; i++) {
        cin >> roads[i].a >> roads[i].b >> roads[i].c;
    }

    int count = 0;
    bool startSide = isOnSameSide(x1, y1, roads[0]);
    bool endSide = isOnSameSide(x2, y2, roads[0]);

    for (int i = 0; i < n; i++) {
        if (isOnSameSide(x1, y1, roads[i]) != startSide) {
            count++;
            startSide = !startSide;
        }
        if (isOnSameSide(x2, y2, roads[i]) != endSide) {
            count++;
            endSide = !endSide;
        }
    }

    cout << count/2 << endl;

    return 0;
}