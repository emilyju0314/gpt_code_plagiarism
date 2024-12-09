#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.length();
    int max_length = 2 * k;
    for (int i = 1; i <= n/2; i++) {
        if (s.substr(0, i) == s.substr(i, i)) {
            max_length = max(max_length, i + k);
        }
    }

    cout << max_length * 2 << endl;

    return 0;
}