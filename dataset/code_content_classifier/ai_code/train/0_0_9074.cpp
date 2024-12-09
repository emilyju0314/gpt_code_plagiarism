#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int operations = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i-1] == '1' && s[i] == '0' && s[i+1] == '1') {
            operations++;
            s[i+1] = '0'; // Replace the token at Z
        }
    }

    cout << operations << endl;

    return 0;
}