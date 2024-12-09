#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string b;
        cin >> b;

        string a;
        a += '1'; // Set the first digit of a to 1

        for (int i = 1; i < n; i++) {
            if (b[i] == '1') {
                // If the current digit of b is 1, set the corresponding digit of a to 1
                if (a[i - 1] == '1') {
                    a += '0';
                } else {
                    a += '1';
                }
            } else {
                // If the current digit of b is 0, set the corresponding digit of a to 0
                a += '1';
            }
        }

        cout << a << endl;
    }

    return 0;
}