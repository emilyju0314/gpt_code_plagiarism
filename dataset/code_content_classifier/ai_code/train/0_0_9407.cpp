#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        double result = 1.0 * (2*a*b + a*a) / (2*a*b);
        cout << setprecision(10) << fixed << result << endl;
    }

    return 0;
}