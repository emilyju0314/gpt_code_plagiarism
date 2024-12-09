#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    double max_val = x * y * z;
    string expression = "x*y*z";

    if (x * y * z < x * z * y) {
        max_val = x * z * y;
        expression = "x*z*y";
    }

    if (x * y * z < (x * y) * z) {
        max_val = (x * y) * z;
        expression = "(x*y)*z";
    }

    if (x * y * z < (x * z) * y) {
        max_val = (x * z) * y;
        expression = "(x*z)*y";
    }

    if (x * y * z < y * x * z) {
        max_val = y * x * z;
        expression = "y*x*z";
    }

    if (x * y * z < y * z * x) {
        max_val = y * z * x;
        expression = "y*z*x";
    }

    if (x * y * z < (y * x) * z) {
        max_val = (y * x) * z;
        expression = "(y*x)*z";
    }

    if (x * y * z < (y * z) * x) {
        max_val = (y * z) * x;
        expression = "(y*z)*x";
    }

    if (x * y * z < z * x * y) {
        max_val = z * x * y;
        expression = "z*x*y";
    }

    if (x * y * z < z * y * x) {
        max_val = z * y * x;
        expression = "z*y*x";
    }

    if (x * y * z < (z * x) * y) {
        max_val = (z * x) * y;
        expression = "(z*x)*y";
    }

    if (x * y * z < (z * y) * x) {
        max_val = (z * y) * x;
        expression = "(z*y)*x";
    }

    cout << expression << endl;

    return 0;
}