#include <iostream>
#include <cmath>

using namespace std;

bool isRightTriangle(int a, int b, int c) {
    if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a)) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (isRightTriangle(a, b, c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}