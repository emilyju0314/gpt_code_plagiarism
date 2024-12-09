#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, k;
        cin >> a >> b >> k;

        int gcd = __gcd(a, b);
        int min_moves = 2;

        if(a == b) {
            if(k == 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            if((a/gcd)*(b/gcd) <= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}