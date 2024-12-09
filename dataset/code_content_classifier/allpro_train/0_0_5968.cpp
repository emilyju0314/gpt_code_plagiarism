#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x, y, z;
    cin >> x >> y >> z;

    int output = 2 * (a * x * y + b * y * z + c * z * x) + 8 * d;

    cout << output;

    return 0;
}