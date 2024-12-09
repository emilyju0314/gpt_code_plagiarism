#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A <= B) {
        cout << 0 << endl;
    } else {
        cout << A - 2*B << endl;
    }

    return 0;
}