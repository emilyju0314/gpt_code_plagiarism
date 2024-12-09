#include <iostream>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double ans;
    
    if (a == 0 || b == 0) {
        ans = abs(x2 - x1) + abs(y2 - y1);
    } else {
        if ((a * x1 + b * y1 + c) * (a * x2 + b * y2 + c) > 0) {
            ans = distance(x1, y1, x2, y2);
        } else {
            ans = abs(a * (x2 - x1) + b * (y2 - y1)) / sqrt(a * a + b * b);
        }
    }
    
    cout << fixed;
    cout.precision(10);
    cout << ans << endl;
    
    return 0;
}