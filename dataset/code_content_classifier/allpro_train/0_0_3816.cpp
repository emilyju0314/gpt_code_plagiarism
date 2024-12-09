#include <iostream>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    double dist = distance(x1, y1, x2, y2);

    // Traveling along the avenue
    double dist_avenue = abs(a*x1 + b*y1 + c) / sqrt(a*a + b*b) + abs(a*x2 + b*y2 + c) / sqrt(a*a + b*b);
    
    // Traveling horizontally or vertically
    double dist_horizontal = abs(x2 - x1) + abs(y2 - y1);

    // Taking a diagonal path
    double dist_diagonal = max(abs(x2 - x1), abs(y2 - y1)) + 1.414213562 * min(abs(x2 - x1), abs(y2 - y1));

    double result = min({dist, dist_avenue, dist_horizontal, dist_diagonal});

    cout << fixed;
    cout.precision(10);
    cout << result << endl;

    return 0;
}