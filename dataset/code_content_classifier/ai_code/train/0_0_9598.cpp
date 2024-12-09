#include <iostream>
#include <string>

using namespace std;

int main() {
    string c11, c12, c13, c21, c22, c23, c31, c32, c33;
    cin >> c11 >> c12 >> c13;
    cin >> c21 >> c22 >> c23;
    cin >> c31 >> c32 >> c33;

    cout << c11[0] << c22[1] << c33[2] << endl;

    return 0;
}