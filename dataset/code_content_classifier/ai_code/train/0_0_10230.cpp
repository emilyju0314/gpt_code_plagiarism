#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int count = 0;

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            for (int x = l; x < r-2; x++) {
                for (int k = 1; x + 2*k <= r; k++) {
                    if (s[x-1] == s[x+k-1] && s[x-1] == s[x+2*k-1]) {
                        count++;
                        break; // Move to next l, r pair
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}