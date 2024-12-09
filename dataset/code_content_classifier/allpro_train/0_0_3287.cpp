#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (B % A == 0) {
        cout << -1 << endl;
    } else {
        int minAmount = B / A + 1;
        cout << A * minAmount << endl;
    }

    return 0;
}