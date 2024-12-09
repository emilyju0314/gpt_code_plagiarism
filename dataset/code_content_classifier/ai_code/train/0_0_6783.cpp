#include<iostream>
using namespace std;

int main() {
    int a1, a2;
    cin >> a1 >> a2;

    // Check if a1 and a2 have the same parity (both even or both odd)
    if ((a1 % 2 == 0 && a2 % 2 == 0) || (a1 % 2 == 1 && a2 % 2 == 1)) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}