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

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n]) {
                count++;
            }
        }

        cout << (count + 1) / 2 << endl;
    }

    return 0;
}