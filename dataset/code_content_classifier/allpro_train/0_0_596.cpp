#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

double cross_product(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main() {
    int N;
    cin >> N;

    vector<Point> vertices(N);
    for (int i = 0; i < N; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    for (int i = 0; i < N; i++) {
        Point A = vertices[i];
        Point B = vertices[(i + 1) % N];
        double cut_area = 0;
        
        for (int j = 0; j < N; j++) {
            Point C = vertices[j];
            Point D = vertices[(j + 1) % N];
            double area1 = 0.5 * abs(cross_product(A, B, C));
            double area2 = 0.5 * abs(cross_product(A, B, D));
            cut_area += min(area1, area2);
        }

        if (abs(cut_area - 0.5 * abs(cross_product(A, B, vertices[(i + 2) % N]))) < 1e-9) {
            double Px = 0.5 * (A.x + B.x);
            double Py = 0.5 * (A.y + B.y);
            cout << fixed << Px << " " << Py << endl;
            return 0;
        }
    }

    cout << "NA" << endl;

    return 0;
}