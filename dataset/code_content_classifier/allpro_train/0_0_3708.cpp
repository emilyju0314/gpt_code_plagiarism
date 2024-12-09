#include<iostream>
using namespace std;

int main() {
    // Input
    int A, B, C;
    cin >> A >> B >> C;

    // Find the integer that is different from the rest
    if (A == B) {
        cout << C << endl;
    } else if (A == C) {
        cout << B << endl;
    } else {
        cout << A << endl;
    }

    return 0;
}