#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int R;
    cin >> R;

    double circumference = 2 * 3.14159265358979323846 * R;

    cout << fixed << setprecision(20) << circumference << endl;

    return 0;
}