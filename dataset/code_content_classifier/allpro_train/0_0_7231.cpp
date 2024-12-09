#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    double discriminant = b*b - 4*a*c;
    double root1 = (-b + sqrt(discriminant)) / (2*a);
    double root2 = (-b - sqrt(discriminant)) / (2*a);

    if(root1 > root2) {
        cout << fixed << root1 << endl;
        cout << fixed << root2 << endl;
    } else {
        cout << fixed << root2 << endl;
        cout << fixed << root1 << endl;
    }

    return 0;
}