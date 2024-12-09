#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int S, a, b, c;
    cin >> S >> a >> b >> c;

    double sum = a + b + c;

    double x = (double) S * a / sum;
    double y = (double) S * b / sum;
    double z = (double) S * c / sum;

    printf("%.10f %.10f %.10f\n", x, y, z);

    return 0;
}