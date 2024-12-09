#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    int sp = 7; // Prime number
    int mstw = 13; // Prime number
    cout << sp << " " << mstw << endl;

    int u = 1, v = 2, w = 2; // Edge weights to create the MST
    for(int i=0; i<m; i++) {
        cout << u << " " << v << " " << w << endl;
        v++;
        if(v > n) {
            u++;
            v = u + 1;
        }
        w++;
    }

    return 0;
}