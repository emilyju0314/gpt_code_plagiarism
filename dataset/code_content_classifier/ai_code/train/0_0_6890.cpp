#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4;
    cin >> num1 >> num2 >> num3 >> num4;

    int sum = num1 + num2 + num3 + num4;

    if (sum >= 2) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}