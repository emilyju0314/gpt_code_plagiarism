#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Planet {
    int x, y, z;
};

double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<Planet> planets(n);
    for(int i = 0; i < n; i++) {
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
    }
    
    Planet base;
    double max_dist = 0;
    
    for(int i = 0; i < n; i++) {
        double min_dist = INT_MAX;
        for(int j = 0; j < n; j++) {
            min_dist = min(min_dist, distance(planets[i], planets[j]));
        }
        if(min_dist > max_dist) {
            max_dist = min_dist;
            base = planets[i];
        }
    }
    
    cout << base.x << " " << base.y << " " << base.z << endl;
    
    return 0;
}