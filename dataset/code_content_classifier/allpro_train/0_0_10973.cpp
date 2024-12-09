#include <iostream>
#include <cmath>

using namespace std;

int fractal_distance(int a, int b, int c, int d) {
    int distance = 0;
    
    while (a != c || b != d) {
        int size = pow(3, distance);
        
        int subgrid_a = a / (size / 3);
        int subgrid_b = b / (size / 3);
        int subgrid_c = c / (size / 3);
        int subgrid_d = d / (size / 3);
        
        if (subgrid_a == subgrid_c && subgrid_b == subgrid_d) {
            distance += 1;
            a = subgrid_a;
            b = subgrid_b;
            c = subgrid_c;
            d = subgrid_d;
        } else {
            distance += abs(a - c) + abs(b - d);
            break;
        }
    }
    
    return distance;
}

int main() {
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int result = fractal_distance(a, b, c, d);
        cout << result << endl;
    }
    
    return 0;
}