#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a > b * c) {
            cout << -1 << endl;
        } else {
            long long maxHealth = a;
            long long extraDamage = a;

            while(extraDamage > b * c) {
                extraDamage = (extraDamage - b * c) + a;
                maxHealth += a;
            }

            if(extraDamage % d == 0) {
                cout << maxHealth + (extraDamage / d) * b << endl;
            } else {
                cout << maxHealth + (extraDamage / d + 1) * b << endl;
            }
        }
    }

    return 0;
}