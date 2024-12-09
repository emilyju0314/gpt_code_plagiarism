#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long x_0, n;
        cin >> x_0 >> n;

        long long k = (sqrt(1 + 8*n) - 1) / 2;
        long long position;
        if(k % 2 == 0) {
            position = x_0 + n - (k*(k+1))/2;
        } else {
            position = x_0 + n - (k*(k+1))/2 + k;
        }

        if(abs(position) % 2 == 0) {
            cout << abs(position) / 2 << endl;
        } else {
            cout << -((abs(position) + 1) / 2) << endl;
        }
    }

    return 0;
}