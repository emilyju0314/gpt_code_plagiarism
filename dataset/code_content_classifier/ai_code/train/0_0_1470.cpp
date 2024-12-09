#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double W, H, S;
    
    while (cin >> W >> H >> S) {
        if (W == 0 && H == 0 && S == 0) {
            break;
        }
        
        double total_power = 0;
        
        for (int i = 1; i <= min(W, H); i++) {
            double R = min(i, min(W - i, H - i)) / 2.0;
            total_power += R * R * 4 * M_PI;
        }
        
        cout << fixed << setprecision(3) << total_power << endl;
    }
    
    return 0;
}