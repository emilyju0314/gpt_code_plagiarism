#include <bits/stdc++.h>
using namespace std;

struct Point {
    int a, b, c, d;
    int index;
};

bool cmp(Point &p1, Point &p2) {
    return p1.a * p2.b < p1.b * p2.a;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].a >> points[i].b >> points[i].c >> points[i].d;
        points[i].index = i + 1;
    }
    
    sort(points.begin(), points.end(), cmp);
    
    vector<pair<int, int>> moves;
    
    for (int i = 1; i < n; i += 2) {
        moves.push_back({points[i-1].index, points[i].index});
    }
    
    cout << moves.size() << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << endl;
    }
    
    return 0;
}