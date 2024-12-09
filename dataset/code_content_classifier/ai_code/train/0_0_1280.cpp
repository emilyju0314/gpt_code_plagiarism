#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, index;
    Point(int x, int y, int index) : x(x), y(y), index(index) {}
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

int main() {
    int N;
    cin >> N;

    vector<Point> spaceships, bases;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        spaceships.push_back(Point(x, y, i+1));
    }

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        bases.push_back(Point(x, y, i+1));
    }

    sort(spaceships.begin(), spaceships.end(), compareX);
    sort(bases.begin(), bases.end(), compareX);

    vector<int> result;
    for (int i = 0; i < N; i++) {
        result.push_back(bases[i].index);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }

    return 0;
}