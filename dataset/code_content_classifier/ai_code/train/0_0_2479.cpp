#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string filler = "ogo";
    string replacement = "***";

    string result;
    int i = 0;
    while (i < n) {
        if (s.substr(i, filler.length()) == filler) {
            result += replacement;
            i += filler.length();
        } else {
            result += s[i];
            i++;
        }
    }

    cout << result << endl;

    return 0;
}