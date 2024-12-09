#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    // Reverse the integer
    int reverse = 0;
    while(a != 0) {
        int digit = a % 10;
        reverse = reverse * 10 + digit;
        a /= 10;
    }

    // Multiply the reverse by 2 and add 1 to get the output
    int output = reverse * 2 + 1;
    cout << output << endl;

    return 0;
}