#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int area1 = A * B;
    int area2 = C * D;

    if (area1 > area2) {
        cout << area1 << endl;
    } else if (area2 > area1) {
        cout << area2 << endl;
    } else {
        cout << area1 << endl;
    }

    return 0;
}