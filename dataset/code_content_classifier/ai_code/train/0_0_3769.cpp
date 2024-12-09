#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, r, v;
    cin >> n >> r >> v;
    
    for(int i = 0; i < n; i++) {
        int si, fi;
        cin >> si >> fi;
        
        double d = fi - si;
        double t = d / (2 * v);
        
        if (t == 0) {
            cout << fixed << setprecision(10) << d / v << endl;
        } else {
            double x = v * t;
            double d1 = sqrt(x * x + r * r);
            double time = d1 + d - x;
            cout << fixed << setprecision(10) << time << endl;
        }
    }
    
    return 0;
}