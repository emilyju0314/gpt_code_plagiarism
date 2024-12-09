#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
       return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int c, d, x;
        cin >> c >> d >> x;

        long long count = 0;
        for(int i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                int a = i + d;
                if(a % c == 0) {
                    int b = a / c;
                    if(gcd(a, b) == d) {
                        count++;
                    }
                }

                if(i * i != x) {
                    int a = x / i + d;
                    if(a % c == 0) {
                        int b = a / c;
                        if(gcd(a, b) == d) {
                            count++;
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}