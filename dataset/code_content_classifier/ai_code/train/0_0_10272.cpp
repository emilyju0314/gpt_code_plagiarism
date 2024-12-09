#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Start with the maximum possible number able to be formed
    int number = 0;

    // Try to set segments to form the maximum number while staying within the limit of n segments
    for (int i = 0; i < n; i++) {
        if (n - i > 2) {
            number = number * 10 + 7; // Set a segment for digit 7
            n -= 3;
        } else {
            number = number * 10 + 1; // Set a segment for digit 1
            n -= 2;
        }
    }

    cout << number << endl;

    return 0;
}