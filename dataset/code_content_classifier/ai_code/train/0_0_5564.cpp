#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int totalDigits = 0;
        for (int i = 0; i < x.length(); i++) {
            totalDigits += (x[i] - '0') * (i + 1);
        }

        cout << totalDigits << endl;
    }

    return 0;
}