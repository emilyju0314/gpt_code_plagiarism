#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool isSquare = false;
        int n = s.length();

        if (n % 2 == 0) {
            string p = s.substr(0, n/2);
            string q = s.substr(n/2);
            if (p == q) {
                isSquare = true;
            }
        }

        if (isSquare) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}