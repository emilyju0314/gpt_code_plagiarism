#include <iostream>
using namespace std;

int main() {
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;

    int phases = 0;
    while (h2 > 0) {
        if (h1 <= a2) {
            h1 += c1;
            cout << "HEAL" << endl;
        } else {
            h2 -= a1;
            cout << "STRIKE" << endl;
        }
        h1 -= a2;
        phases++;
    }

    cout << phases << endl;

    return 0;
}