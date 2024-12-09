#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.14159265358979323846;

double calculateAngle(const vector<pair<double, double>>& stars1, const vector<pair<double, double>>& stars2) {
    vector<double> angles1, angles2;
    
    for (int i = 0; i < stars1.size(); i++) {
        double angle1 = atan2(stars1[(i+1)%stars1.size()].second - stars1[i].second, stars1[(i+1)%stars1.size()].first - stars1[i].first);
        double angle2 = atan2(stars2[(i+1)%stars2.size()].second - stars2[i].second, stars2[(i+1)%stars2.size()].first - stars2[i].first);
        
        angles1.push_back(angle1);
        angles2.push_back(angle2);
    }
    
    sort(angles1.begin(), angles1.end());
    sort(angles2.begin(), angles2.end());
    
    double minAngleDiff = PI;
    
    for (int i = 0; i < stars1.size(); i++) {
        double angleDiff = angles2[i] - angles1[i];
        
        if (angleDiff < 0) {
            angleDiff += 2*PI;
        }
        
        if (angleDiff < minAngleDiff) {
            minAngleDiff = angleDiff;
        }
    }
    
    return minAngleDiff;
}

int main() {
    int n;
    cin >> n;
    
    while (n != 0) {
        vector<pair<double, double>> stars1, stars2;
        
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            stars1.push_back(make_pair(x, y));
        }
        
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            stars2.push_back(make_pair(x, y));
        }
        
        double angleDiff = calculateAngle(stars1, stars2);
        cout << angleDiff << endl;
        
        cin >> n;
    }
    
    return 0;
}