#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string result = "";
    char prevChar = '\0'; // Initialize to some arbitrary value

    for (char c : s) {
        if (c == ',') {
            if (prevChar != ' ') {
                result += ' ';
            }
            result += c;
            result += ' ';
        } else if (c == '.') {
            if (prevChar != ' ') {
                result += ' ';
            }
            result += c;
        } else if (c >= '0' && c <= '9') {
            if (prevChar == ' ') {
                result.pop_back(); // Remove the extra space
            }
            result += c;
        } else if (c == ' ') {
            if (prevChar != ' ') {
                result += c;
            }
        }
        prevChar = c;
    }

    cout << result << endl;

    return 0;
}