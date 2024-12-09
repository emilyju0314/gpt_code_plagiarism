#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> particles(n);
    for(int i = 0; i < n; i++) {
        cin >> particles[i].first >> particles[i].second;
    }
    
    double t = -1; // Initialize time to -1 if there is no collision
    
    for(int i = 0; i < n-1; i++) {
        double collision_time = (double)(particles[i+1].first - particles[i].first) / (particles[i].second - particles[i+1].second);
        
        if((collision_time > 0) && (t == -1 || collision_time < t)) {
            t = collision_time;
        }
    }
    
    cout.precision(20);
    cout << t << endl;
    
    return 0;
}