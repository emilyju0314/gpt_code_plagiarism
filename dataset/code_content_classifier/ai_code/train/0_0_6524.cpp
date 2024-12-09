#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long count = 0;
    
    for (long long a = 1; a*a*a <= n; a++) {
        if (n % a == 0) {
            for (long long b = a; a*b*b <= n; b++) {
                if (n % (a*b) == 0) {
                    long long c = n / (a*b);
                    if (c >= b && (a + b + c) % 2 == 0) {
                        long long d = (a + b + c) / 2;
                        if (a + b >= d && a + c >= d && b + c >= d) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}