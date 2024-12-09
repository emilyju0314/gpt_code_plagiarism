#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

struct Road {
    int a, b, w;
};

double distanceToFarthestJunction(vector<Road>& roads, double x) {
    double maxDist = 0;
    for (const Road& road : roads) {
        double distA = x + (double)road.w / 2;
        double distB = road.w - distA;
        maxDist = max({maxDist, distA, distB});
    }
    return maxDist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Road> roads(m);
    
    for (int i = 0; i < m; i++) {
        cin >> roads[i].a >> roads[i].b >> roads[i].w;
    }
    
    double l = 0, r = 1e5;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (distanceToFarthestJunction(roads, mid) < distanceToFarthestJunction(roads, mid + EPS)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    
    cout << fixed << setprecision(9) << distanceToFarthestJunction(roads, l) << endl;
    
    return 0;
}