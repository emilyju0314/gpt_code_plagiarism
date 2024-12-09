#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    long long total_squares1 = a1 * b1;
    long long total_squares2 = a2 * b2;

    if (total_squares1 > total_squares2) {
        swap(a1, a2);
        swap(b1, b2);
        swap(total_squares1, total_squares2);
    }

    int minutes = 0;

    while ((a1 != a2 || b1 != b2) && total_squares1 != total_squares2) {
        if (total_squares1 < total_squares2) {
            if (a2 % 2 == 0 && a2 / 2 >= a1) {
                a2 /= 2;
            } else if (b2 % 2 == 0 && b2 / 2 >= b1) {
                b2 /= 2;
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
            if (a2 % 3 == 0 && a2 / 3 >= a1) {
                a2 /= 3;
            } else if (b2 % 3 == 0 && b2 / 3 >= b1) {
                b2 /= 3;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
        
        total_squares2 = a2 * b2;
        minutes++;
    }

    cout << minutes << endl;
    cout << a1 << " " << b1 << endl;
    cout << a2 << " " << b2 << endl;

    return 0;
}