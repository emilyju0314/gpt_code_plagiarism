#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        int sum = 1; // 1 is always a divisor
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                sum += i; // adding the divisor
                if (n/i != i) {
                    sum += n/i; // adding the other divisor
                }
            }
        }
        
        if (n == sum) {
            cout << "perfect number" << endl;
        } else if (n < sum) {
            cout << "abundant number" << endl;
        } else {
            cout << "deficient number" << endl;
        }
    }
    
    return 0;
}