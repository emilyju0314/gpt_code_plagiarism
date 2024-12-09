#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if(a + b + c + d == 0) {
        cout << fixed << setprecision(12) << 0.0 << endl;
    } else {
        cout << fixed << setprecision(12) << e / (a + b + c + d) << endl;
    }

    return 0;
}