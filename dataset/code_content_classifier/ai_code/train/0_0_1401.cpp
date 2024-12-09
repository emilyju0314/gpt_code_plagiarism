#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct Point {
    long long x, y;
};

int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; // 1 for clockwise, 2 for counterclockwise
}

vector<Point> getMinkowskiSum(const vector<Point>& A, const vector<Point>& B) {
    vector<Point> sum;

    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;

    int a = 0, b = 0;
    for (int a = 0; a < n; ++a) {
        sum.push_back({A[a].x + B[b].x, A[a].y + B[b].y});
        if (orientation(A[(a+1)%n], B[b], B[(b+1)%m]) == 2) {
            ++b;
            if (b == m) b = 0;
        }
        if (orientation(A[a], B[(b+1)%m], B[b]) == 1) {
            --a;
            if (a == -1) a = n-1;
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Point>> polygons(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        polygons[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> polygons[i][j].x >> polygons[i][j].y;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        
        vector<Point> sum = polygons[l-1];
        for (int j = l; j < r; ++j) {
            sum = getMinkowskiSum(sum, polygons[j]);
        }

        set<pair<long long, long long>> unique_vertices;
        for (auto point : sum) {
            unique_vertices.insert({point.x, point.y});
        }

        cout << unique_vertices.size() << endl;
    }

    return 0;
}