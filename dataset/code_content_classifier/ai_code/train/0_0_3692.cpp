#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    for (int i = 1; i <= n - 1; i++) {
        double cut_position = h * sqrt(i * 1.0 / n);
        cout << fixed << setprecision(15) << cut_position << " ";
    }

    return 0;
}