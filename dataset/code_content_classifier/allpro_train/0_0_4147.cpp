#include <iostream>

using namespace std;

int main() {
    int a, b, d;
    
    while (true) {
        cin >> a >> b >> d;
        
        if (a == 0 && b == 0 && d == 0) {
            break;
        }
        
        int x = 0, y = d / a;
        int minWeight = y * b;
        
        while (y >= 0) {
            int currentWeight = y * b + (d - y * a);
            if (currentWeight < minWeight) {
                minWeight = currentWeight;
                x = d - y * a;
            }
            y--;
        }
        
        cout << x << " " << d / a - x << endl;
    }
    
    return 0;
}