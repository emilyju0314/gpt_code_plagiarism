#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        
        double x = 0.0, y = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                y += 1.0;
            } else {
                x += 1.0;
            }
        }
        
        cout << fixed;
        cout.precision(2);
        cout << x << endl << y << endl;
    }
    
    return 0;
}