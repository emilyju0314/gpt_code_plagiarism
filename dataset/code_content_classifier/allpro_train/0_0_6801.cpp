#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNice(string s) {
    if (s.length() < 26) {
        return false;
    }
    
    vector<int> count(26, 0);
    int questionMarks = 0;
    
    for (char c : s) {
        if (c == '?') {
            questionMarks++;
        } else {
            count[c - 'A']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            return false;
        }
    }
    
    if (questionMarks < 26) {
        return false;
    }
    
    return true;
}

string fillMissingLetters(string s) {
    vector<int> count(26, 0);
    
    for (char c : s) {
        if (c != '?') {
            count[c - 'A']++;
        }
    }

    string result = s;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) {
            for (char& c : result) {
                if (c == '?') {
                    c = 'A' + i;
                    count[i]++;
                    break;
                }
            }
        }
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    if (isNice(s)) {
        cout << fillMissingLetters(s) << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}