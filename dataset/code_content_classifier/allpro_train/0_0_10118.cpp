#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

struct City {
    int x, y, a;
};

double dist(const City& c1, const City& c2) {
    return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}

bool canDistributeWater(const vector<City>& cities, double X) {
    vector<double> water(cities.size(), X);
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities.size(); j++) {
            double remainingWater = max(X - dist(cities[i], cities[j]), 0.0);
            water[j] = min(water[j], remainingWater);
        }
    }
    
    for (double w : water) {
        if (w < cities[0].a) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<City> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i].x >> cities[i].y >> cities[i].a;
    }
    
    double low = 0, high = 1e9;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (canDistributeWater(cities, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << fixed;
    cout.precision(9);
    cout << low << endl;
    
    return 0;
}