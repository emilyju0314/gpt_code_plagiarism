#include <iostream>

using namespace std;

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    
    int distance = a;
    int refuels = 0;
    int fuel = b;
    
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            if (fuel < distance) {
                cout << -1 << endl;
                return 0;
            }
            fuel -= distance;
            if (i != k - 1 && fuel < 2 * (a - f)) {
                fuel = b;
                refuels++;
            }
        } else {
            if (fuel < a - distance) {
                cout << -1 << endl;
                return 0;
            }
            fuel -= a - distance;
            if (i != k - 1 && fuel < 2 * f) {
                fuel = b;
                refuels++;
            }
        }
        distance = i % 2 == 0 ? a - distance : distance;
    }
    
    cout << refuels << endl;
    
    return 0;
}