#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int T, X;
    cin >> T >> X;

    double hours_in_world_A = (double) T / X;
    cout << fixed << setprecision(10) << hours_in_world_A << endl;

    return 0;
}