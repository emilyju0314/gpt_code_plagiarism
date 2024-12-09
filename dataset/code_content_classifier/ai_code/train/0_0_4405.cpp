#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, k, m, r;
    while (cin >> n >> k >> m >> r) {
        if (n == 0 && k == 0 && m == 0 && r == 0) {
            break;
        }
        
        double success = 0.0;
        
        // Check if there is only one pile
        if (k == 1) {
            success = 1.0;
        } else {
            success = (1.0 - 1.0 / k);
        }
        
        if (m == 1) {
            success = 1.0 - pow(1.0 - success, 2);
        }
        
        cout << fixed << setprecision(r) << success << endl;
    }
    return 0;
}