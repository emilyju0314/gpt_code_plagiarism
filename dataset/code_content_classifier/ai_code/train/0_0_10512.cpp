#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> centers(n);
    for(int i = 0; i < n; i++) {
        cin >> centers[i].first >> centers[i].second;
    }
    
    double max_radius = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double radius = sqrt((centers[i].first - centers[j].first)*(centers[i].first - centers[j].first) + (centers[i].second - centers[j].second)*(centers[i].second - centers[j].second)) / 2;
            
            double min_dist = radius;
            
            for(int k = 0; k < n; k++) {
                if(k == i || k == j) continue;
                
                double dist = sqrt((centers[k].first - centers[i].first)*(centers[k].first - centers[i].first) + (centers[k].second - centers[i].second)*(centers[k].second - centers[i].second));
                
                min_dist = min(min_dist, dist);
            }
            
            max_radius = max(max_radius, min_dist);
        }
    }
    
    cout << fixed;
    cout.precision(20);
    cout << max_radius << endl;
    
    return 0;
}