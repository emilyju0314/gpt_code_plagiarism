#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;

struct SweetShop {
    int x, y, v;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calculateTime(double x, double y, const vector<SweetShop>& shops) {
    double maxTime = 0.0;
    for (const SweetShop& shop : shops) {
        double dist = distance(x, y, shop.x, shop.y);
        maxTime = max(maxTime, dist / shop.v);
    }
    return maxTime;
}

double ternarySearch(double left, double right, const vector<SweetShop>& shops) {
    while (right - left > eps) {
        double m1 = left + (right - left) / 3;
        double m2 = right - (right - left) / 3;
        double time1 = calculateTime(m1, m1, shops);
        double time2 = calculateTime(m2, m2, shops);
        
        if (time1 < time2) {
            right = m2;
        } else {
            left = m1;
        }
    }
    return calculateTime(left, left, shops);
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<SweetShop> shops(N);
        for (int i = 0; i < N; i++) {
            cin >> shops[i].x >> shops[i].y >> shops[i].v;
        }
        
        double result = ternarySearch(0, 100, shops);
        cout << fixed;
        cout.precision(8);
        cout << result << endl;
    }
    
    return 0;
}