#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check if the sum of the four numbers is even
    if ((a + b + c + d) % 2 != 0) {
        cout << "-1" << endl; // If the sum is odd, it's impossible to crack the safe
    } else {
        // Try to make all numbers equal to 1
        while (a != 1 || b != 1 || c != 1 || d != 1) {
            // If two adjacent numbers are equal, add 1 to both
            if (a == b) {
                cout << "+1" << endl;
                a++;
                b++;
            } else if (b == c) {
                cout << "+2" << endl;
                b++;
                c++;
            } else if (c == d) {
                cout << "+3" << endl;
                c++;
                d++;
            } else if (a % 2 == 0 && b % 2 == 0) {
                cout << "/1" << endl;
                a /= 2;
                b /= 2;
            } else if (b % 2 == 0 && c % 2 == 0) {
                cout << "/2" << endl;
                b /= 2;
                c /= 2;
            } else if (c % 2 == 0 && d % 2 == 0) {
                cout << "/3" << endl;
                c /= 2;
                d /= 2;
            } else {
                cout << "/4" << endl;
                b /= 2;
                d /= 2;
            }
        }
    }
    return 0;
}