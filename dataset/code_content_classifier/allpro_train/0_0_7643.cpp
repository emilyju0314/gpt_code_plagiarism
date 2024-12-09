#include <iostream>

using namespace std;

bool hasOddDivisor(long long n) {
    while(n % 2 == 0) {
        n /= 2;
    }
    return n > 1;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        if(hasOddDivisor(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}