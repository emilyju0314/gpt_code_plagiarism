#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long side1 = 1, side2 = a;
    long long minPerimeter = LLONG_MAX;

    for (long long i = 1; i <= sqrt(a + b); i++) {
        if ((a + b) % i == 0) {
            long long j = (a + b) / i;

            if (i <= a && j <= b) {
                long long perimeter = 2 * (i + j);
                if (perimeter < minPerimeter) {
                    minPerimeter = perimeter;
                    side1 = i;
                    side2 = j;
                }
            }

            if (j <= a && i <= b) {
                long long perimeter = 2 * (i + j);
                if (perimeter < minPerimeter) {
                    minPerimeter = perimeter;
                    side1 = j;
                    side2 = i;
                }
            }
        }
    }

    cout << minPerimeter << endl;

    return 0;
}