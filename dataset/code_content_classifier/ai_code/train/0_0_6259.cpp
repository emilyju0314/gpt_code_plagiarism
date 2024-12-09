#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";
    char maxChar = 'a';
    for (char c : s) {
        if (c >= maxChar) {
            result += c;
            maxChar = c;
        }
    }

    cout << result << endl;

    return 0;
}