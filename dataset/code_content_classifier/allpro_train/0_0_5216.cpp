#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    
    int n;
    cin >> n;
    
    int blankets = 0;
    
    for (int i = 0; i < n; i++) {
        int x, y, ri;
        cin >> x >> y >> ri;
        
        for (int j = xa; j <= xb; j++) {
            for (int k = ya; k <= yb; k++) {
                double dist = sqrt((j-x)*(j-x) + (k-y)*(k-y));
                if (dist > ri) blankets++;
            }
        }
    }
    
    cout << blankets << endl;
    
    return 0;
}