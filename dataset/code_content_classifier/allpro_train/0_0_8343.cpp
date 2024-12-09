#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, r;
    cin >> a >> b >> r;

    int min_side = min(a, b);
    int max_side = max(a, b);

    if (min_side >= 2*r) {
        cout << "First" << endl;
    } else {
        double diagonal = sqrt(a*a + b*b);
        if (diagonal >= 2*r) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }

    return 0;
}