#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int min_area = 6 * n;
    if(a * b >= min_area) {
        cout << a * b << endl;
        cout << a << " " << b << endl;
    } else {
        int new_a = a, new_b = b;
        int diff_a = ceil((double)min_area / b);
        int diff_b = ceil((double)min_area / a);

        if(a + diff_a <= b) {
            new_a = b;
            new_b = a + diff_a;
        } else {
            new_a = a + diff_b;
            new_b = b;
        }

        cout << new_a * new_b << endl;
        cout << new_a << " " << new_b << endl;
    }

    return 0;
}