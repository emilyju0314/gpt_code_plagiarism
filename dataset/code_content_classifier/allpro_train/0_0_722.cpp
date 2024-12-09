#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    // checking if the logarithm of n with base 2 is an integer
    if (floor(log2(n)) == ceil(log2(n))) {
        cout << "Petya" << endl;
    } else {
        cout << "Vasya" << endl;
    }

    return 0;
}