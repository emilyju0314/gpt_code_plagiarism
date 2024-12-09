#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Location {
    int x, y, k;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n, s;
    cin >> n >> s;
    
    vector<Location> locations(n);
    for(int i = 0; i < n; i++) {
        cin >> locations[i].x >> locations[i].y >> locations[i].k;
    }
    
    double min_radius = 1e9; // set a very large initial radius value
    
    for(int i = 0; i < n; i++) {
        double dist = distance(0, 0, locations[i].x, locations[i].y);
        min_radius = min(min_radius, dist - sqrt((double)s / locations[i].k));
    }
    
    if(min_radius < 0) {
        cout << -1 << endl; // Tomsk won't be able to become a megacity
    } else {
        cout << fixed;
        cout.precision(7);
        cout << min_radius << endl;
    }
    
    return 0;
}