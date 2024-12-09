#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (s.substr(0, 4) == "2020" || s.substr(n-4, 4) == "2020" ||
            (s.substr(0, 1) == "2" && s.substr(n-3, 3) == "020") ||
            (s.substr(0, 2) == "20" && s.substr(n-2, 2) == "20") ||
            (s.substr(0, 3) == "202" && s.substr(n-1, 1) == "0")) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}