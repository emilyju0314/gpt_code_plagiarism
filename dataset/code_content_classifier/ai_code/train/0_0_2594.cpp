#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool isInsideHole(Point person, int radius) {
    return person.x * person.x + person.y * person.y <= radius * radius;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> radii(n);
    for (int i = 0; i < n; i++) {
        cin >> radii[i];
    }

    vector<vector<Point>> people(m);
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        vector<Point> vertices(p);
        for (int j = 0; j < p; j++) {
            cin >> vertices[j].x >> vertices[j].y;
        }
        people[i] = vertices;
    }

    for (int i = 0; i < m; i++) {
        bool foundHole = false;
        for (int j = 0; j < n; j++) {
            bool canPass = true;
            for (Point vertex : people[i]) {
                if (!isInsideHole(vertex, radii[j])) {
                    canPass = false;
                    break;
                }
            }
            if (canPass) {
                cout << j + 1 << endl;
                foundHole = true;
                break;
            }
        }
        if (!foundHole) {
            cout << "NG" << endl;
        }
    }

    return 0;
}