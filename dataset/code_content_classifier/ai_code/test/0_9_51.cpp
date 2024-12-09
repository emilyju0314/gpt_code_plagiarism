#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long l, r;
        
        r = (-1 + sqrt(1 + 8 * n)) / 2;
        l = n - (r * (r + 1)) / 2;
        cout << l << " " << l + r << endl;
    }

    return 0;
}