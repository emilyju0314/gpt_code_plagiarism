#include <iostream>
#include <string>
using namespace std;

string expandString(string compressed) {
    string expanded;
    for (int i = 0; i < compressed.size(); i++) {
        if (isdigit(compressed[i])) {
            int num = compressed[i] - '0';
            i++;
            while (isdigit(compressed[i])) {
                num = num * 10 + (compressed[i] - '0');
                i++;
            }
            char ch = compressed[i];
            while (num > 0) {
                expanded += ch;
                num--;
            }
        } else if (compressed[i] == '(') {
            string nested = "";
            i++;
            int count = compressed[i] - '0';
            i += 2;
            while (compressed[i] != ')') {
                nested += compressed[i];
                i++;
            }
            string repeated = expandString(nested);
            while (count > 0) {
                expanded += repeated;
                count--;
            }
        } else {
            expanded += compressed[i];
        }
    }
    return expanded;
}

int countOccurrences(string compressed, string pattern) {
    string expanded = expandString(compressed);
    int count = 0;
    for (int i = 0; i <= expanded.size() - pattern.size(); i++) {
        if (expanded.substr(i, pattern.size()) == pattern) {
            count++;
        }
    }
    return count;
}

int main() {
    string s, q;
    while (true) {
        getline(cin, s);
        if (s == "#") {
            break;
        }
        getline(cin, q);
        cout << countOccurrences(s, q) << endl;
    }
    return 0;
}