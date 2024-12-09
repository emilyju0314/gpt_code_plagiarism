#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    double prize = 0.0;
    for (int i = 1; i <= n; i++) {
        prize += 1.0 / i;
    }

    cout << fixed << setprecision(12) << prize << endl;

    return 0;
}