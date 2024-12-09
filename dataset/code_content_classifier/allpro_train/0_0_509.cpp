#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    while(true) {
        int U_W, U_H, A, B, C;
        cin >> U_W >> U_H >> A >> B >> C;
        
        if(U_W == 0 && U_H == 0 && A == 0 && B == 0 && C == 0) {
            break;
        }
        
        double r_A = sqrt(A / M_PI);
        double r_B = sqrt(B / M_PI);
        
        double x_A = r_A;
        double y_A = r_A;
        
        double x_B = U_W - r_B;
        double y_B = r_B;
        
        double dist = sqrt(pow(x_A - x_B, 2) + pow(y_A - y_B, 2));
        
        if((r_A + r_B) > dist && abs(r_A - r_B) < dist) {
            cout << fixed << setprecision(9);
            cout << x_A << " " << y_A << " " << r_A << " " << x_B << " " << y_B << " " << r_B << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}