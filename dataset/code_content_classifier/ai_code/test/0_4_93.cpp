#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;

        long long div = n / k;
        if(div == 0) {
            cout << n << endl;
        } else {
            long long mod = n % k;
            cout << div * k + min(mod, k / 2) << endl;
        }
    }

    return 0;
}