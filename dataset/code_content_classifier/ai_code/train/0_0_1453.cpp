#include <iostream>

using namespace std;

int main() {
    int H, A;
    cin >> H >> A;

    int attacks_needed = (H + A - 1) / A; // rounds up to the nearest integer
    cout << attacks_needed << endl;

    return 0;
}