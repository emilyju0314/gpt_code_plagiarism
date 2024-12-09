#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x, k, p;
    cin >> x >> k >> p;
    
    double result = 0.0;
    
    for(int rnd = 1; rnd <= 100; rnd++) {
        double prob = rnd / 100.0;
        
        int a = x;
        for(int step = 1; step <= k; step++) {
            if(prob <= p/100.0)
                a *= 2;
            else
                a += 1;
        }
        
        int s = 0;
        while(a % 2 == 0) {
            a /= 2;
            s++;
        }
        
        result += prob * s;
    }
    
    cout << setprecision(12) << fixed << result << endl;
    
    return 0;
}