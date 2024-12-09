#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = a + b - c;
    int y = a + c - b;
    int z = b + c - a;

    if (x >= 0 && y >= 0 && z >= 0 && x % 2 == 0 && y % 2 == 0 && z % 2 == 0) {
        cout << x / 2 << " " << y / 2 << " " << z / 2 << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}