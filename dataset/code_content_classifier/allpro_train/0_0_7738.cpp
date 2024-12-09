#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, h, alpha;
    cin >> w >> h >> alpha;
    
    double angle_rad = alpha * M_PI / 180;
    
    double diag = sqrt(pow(w, 2) + pow(h, 2));
    double area = w * h - (w - diag * cos(angle_rad)) * (h - diag * sin(angle_rad));
    
    cout << fixed;
    cout << area << endl;
    
    return 0;
}