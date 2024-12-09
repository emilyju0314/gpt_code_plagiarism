#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long ships = 0;
    while (b != 0) {
        ships += a / b;
        long long temp = b;
        b = a % b;
        a = temp;
    }

    cout << ships << endl;

    return 0;
}