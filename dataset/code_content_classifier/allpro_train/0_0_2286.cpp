#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<double> x(n+1);
    for(int i = 0; i <= n; i++) {
        cin >> x[i];
    }
    
    double y;
    cin >> y;
    
    x.erase(x.begin() + k - 1);
    sort(x.begin(), x.end());
    
    double total_distance = 0;
    double prev_x = x[0];
    double prev_y = 0;
    
    for(int i = 1; i < x.size(); i++) {
        total_distance += distance(prev_x, prev_y, x[i], y);
        prev_x = x[i];
    }
    
    total_distance += distance(prev_x, y, x[0], 0);
    
    cout.precision(20);
    cout << total_distance << endl;
    
    return 0;
}