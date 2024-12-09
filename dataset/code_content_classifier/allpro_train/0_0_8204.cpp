#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int A, B;
    cin >> A >> B;
    
    int common_divisors = gcd(A, B);
    
    int result = 1;
    for (int i = 2; i <= sqrt(common_divisors); i++) {
        if (common_divisors % i == 0) {
            result++;
            if (i != common_divisors / i) {
                result++;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}