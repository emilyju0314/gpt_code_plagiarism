#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    int totalTriangles = a1*a2 + a2*a3 + a3*a4 + a4*a5 + a5*a6 + a6*a1;
    totalTriangles += a1 + a2 + a3 + a4 + a5 + a6 - 6;

    cout << totalTriangles << endl;

    return 0;
}