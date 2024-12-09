#include <iostream>
using namespace std;

int main() {
    int A1, B1, C1, A2, B2, C2;
    cin >> A1 >> B1 >> C1;
    cin >> A2 >> B2 >> C2;

    int determinant = A1*B2 - A2*B1;
    
    if (determinant == 0 && C1*B2 != C2*B1) {
        cout << 0 << endl;  // No points in intersection
    } else if (determinant == 0 && C1*B2 == C2*B1) {
        cout << -1 << endl;  // Infinite number of points in intersection
    } else {
        cout << 1 << endl;  // One point in intersection
    }

    return 0;
}