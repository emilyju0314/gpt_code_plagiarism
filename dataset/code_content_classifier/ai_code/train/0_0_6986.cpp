#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X;
    cin >> X;

    int A = round(pow(X, 1.0 / 5)); // calculate A using X^(1/5)
    int B = round(pow(A*A*A*A*A - X, 1.0 / 5)); // calculate B using A^5 - X

    cout << A << " " << -B << endl; // print A and -B

    return 0;
}