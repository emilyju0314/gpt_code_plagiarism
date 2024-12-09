#include <iostream>

using namespace std;

int main() {
    int k, r;
    cin >> k >> r;

    int shovels = 1;
    int totalPrice = k;

    while (totalPrice % 10 != 0 && totalPrice % 10 != r) {
        shovels++;
        totalPrice += k;
    }

    cout << shovels << endl;

    return 0;
}