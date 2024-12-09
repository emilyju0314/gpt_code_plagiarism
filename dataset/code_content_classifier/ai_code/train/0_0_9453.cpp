#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    while(n > 0) {
        int numStonesToTake = gcd(a, n);
        if(numStonesToTake > n) {
            cout << "1" << endl;
            break;
        }
        n -= numStonesToTake;
        numStonesToTake = gcd(b, n);
        if(numStonesToTake > n) {
            cout << "0" << endl;
            break;
        }
        n -= numStonesToTake;
    }

    return 0;
}