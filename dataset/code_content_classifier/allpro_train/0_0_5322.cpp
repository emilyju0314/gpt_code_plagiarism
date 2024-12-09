#include <iostream>
#include <vector>

using namespace std;

struct Road {
    int a, b, c;
};

double distance(int x, int y, Road road) {
    return (double)(road.a * x + road.b * y + road.c) / sqrt(road.a * road.a + road.b * road.b);
}

int main() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    vector<Road> roads(n);

    for (int i = 0; i < n; i++) {
        cin >> roads[i].a >> roads[i].b >> roads[i].c;
    }

    int min_steps = INT_MAX;

    for (int i = 0; i < n; i++) {
        double dist_home = distance(x1, y1, roads[i]);
        double dist_university = distance(x2, y2, roads[i]);

        if ((dist_home > 0 && dist_university < 0) || (dist_home < 0 && dist_university > 0)) {
            min_steps = min(min_steps, 1);
        }
    }

    if (min_steps == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << min_steps << endl;
    }

    return 0;
}