#include <iostream>
#include <cmath>

using namespace std;

double calculateArea(double angleSum) {
    return 0.5 * sin(angleSum * M_PI / 180);
}

int main() {
    int m, n;
    
    while (true) {
        cin >> m;
        if (m == 0) {
            break;
        }
        
        double angleSum1 = 0.0;
        for (int i = 0; i < m - 1; i++) {
            int angle;
            cin >> angle;
            angleSum1 += angle;
        }
        
        double area1 = calculateArea(angleSum1);
        
        cin >> n;
        
        double angleSum2 = 0.0;
        for (int i = 0; i < n - 1; i++) {
            int angle;
            cin >> angle;
            angleSum2 += angle;
        }
        
        double area2 = calculateArea(angleSum2);
        
        if (area1 > area2) {
            cout << "1" << endl;
        } else if (area1 < area2) {
            cout << "2" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}