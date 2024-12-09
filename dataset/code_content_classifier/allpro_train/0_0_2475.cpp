#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    
    double angle = 2 * M_PI / n;
    double area = 0.5 * n * pow(r, 2) * sin(angle);
    
    cout << fixed << area << endl;
    
    return 0;
}