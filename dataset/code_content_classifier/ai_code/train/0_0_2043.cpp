#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int max_fruits = 0;

    while (a >= 1 && b >= 2 && c >= 4) {
        max_fruits += (1 + 2 + 4);
        a--;
        b -= 2;
        c -= 4;
    }

    cout << max_fruits << endl;

    return 0;
}