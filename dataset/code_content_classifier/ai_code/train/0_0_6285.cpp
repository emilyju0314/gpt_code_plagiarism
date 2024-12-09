#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (true) {
        n++;
        int temp = n;
        bool isLucky = true;
        int countNonZeroDigits = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0) {
                countNonZeroDigits++;
            }
            temp /= 10;
        }

        if (countNonZeroDigits <= 1) {
            cout << n - n << endl;
            break;
        }
    }

    return 0;
}