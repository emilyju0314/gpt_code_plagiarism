#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int R0, W0, C, R;
    while (cin >> R0 >> W0 >> C >> R) {
        if (R0 == 0 && W0 == 0 && C == 0 && R == 0) break;
        
        int X = ceil((double)(R0 * C - R0) / R);
        cout << X << endl;
    }
    
    return 0;
}