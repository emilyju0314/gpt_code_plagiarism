#include <iostream>
using namespace std;

int main() {
    int n, leftOnes = 0, leftZeros = 0, rightOnes = 0, rightZeros = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int li, ri;
        cin >> li >> ri;
        
        if (li == 1) leftOnes++;
        else leftZeros++;
        
        if (ri == 1) rightOnes++;
        else rightZeros++;
    }
    
    int t = min(leftOnes, leftZeros) + min(rightOnes, rightZeros);
    cout << t << endl;
    
    return 0;
}