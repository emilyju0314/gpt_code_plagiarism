#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int x;
    int y;
    int a;
};

bool compare(Rectangle r1, Rectangle r2) {
    return r1.a > r2.a;
}

int main() {
    int n;
    cin >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].x >> rectangles[i].y >> rectangles[i].a;
    }

    sort(rectangles.begin(), rectangles.end(), compare);

    long long totalArea = 0;
    long long maxExtraArea = 0;
    for (int i = 0; i < n; i++) {
        totalArea += (long long) rectangles[i].x * rectangles[i].y;
        maxExtraArea = max(maxExtraArea, totalArea - (long long) rectangles[i].a);
    }

    cout << maxExtraArea << endl;

    return 0;
}