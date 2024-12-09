#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        if(__gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }
    }

    return 0;
}