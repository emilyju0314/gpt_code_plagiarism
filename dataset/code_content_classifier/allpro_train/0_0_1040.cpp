#include <iostream>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.empty() || s.size() > 3) {
        return false;
    }
    if (s.size() > 1 && s[0] == '0') {
        return false;
    }
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

int countValidDelimiters(string s) {
    int count = 0;
    for (int i = 1; i < 4 && i < s.size(); i++) {
        string first = s.substr(0, i);
        if (isValid(first)) {
            for (int j = 1; i+j < s.size() && j < 4; j++) {
                string second = s.substr(i, j);
                if (isValid(second)) {
                    for (int k = 1; i+j+k < s.size() && k < 4; k++) {
                        string third = s.substr(i+j, k);
                        if (isValid(third)) {
                            string fourth = s.substr(i+j+k);
                            if (isValid(fourth)) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    
    cout << countValidDelimiters(s) << endl;
    
    return 0;
}