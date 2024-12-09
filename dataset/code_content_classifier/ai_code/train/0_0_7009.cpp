#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    // If the total number of blocks is even, Homura wins, otherwise Tempura wins
    if ((A * B * C) % 2 == 0) {
        cout << "Hom" << endl;
    } else {
        cout << "Tem" << endl;
    }

    return 0;
}