#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int lastDigit = N % 10;

    if (lastDigit == 2 || lastDigit == 4 || lastDigit == 5 || lastDigit == 7 || lastDigit == 9) {
        cout << "hon" << endl;
    } else if (lastDigit == 0 || lastDigit == 1 || lastDigit == 6 || lastDigit == 8) {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }

    return 0;
}