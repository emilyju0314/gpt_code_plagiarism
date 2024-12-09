#include<iostream>
using namespace std;

int main() {
    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;

    int a, b, c;
    // Since x1 + x2 = a + b, x1 + x3 = a + c, x2 + x3 = b + c
    // and x1 + x2 + x3 = a + b + c, we can find a, b, c as follows:
    a = (x1 + x2 - x3) / 2;
    b = x1 - a;
    c = x2 - b;

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}