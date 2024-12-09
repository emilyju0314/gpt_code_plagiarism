#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isNumberToken(string token) {
    for (char c : token) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isWordToken(string token) {
    for (char c : token) {
        if (!isalnum(c) && c != '_' && c != '$') {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> reservedTokens(n);
    map<string, string> wordMap;

    for (int i = 0; i < n; i++) {
        cin >> reservedTokens[i];
    }

    int m;
    cin >> m;
    cin.ignore();

    while (m--) {
        string line;
        getline(cin, line);

        string result;
        string currentToken;
        
        for (char c : line) {
            if (isalnum(c) || c == '_' || c == '$') {
                currentToken += c;
            } else {
                if (!currentToken.empty()) {
                    if (isNumberToken(currentToken) || isWordToken(currentToken)) {
                        if (wordMap.find(currentToken) == wordMap.end()) {
                            wordMap[currentToken] = ""; // generate next word
                        }
                        result += wordMap[currentToken];
                    } else {
                        result += currentToken;
                    }
                    currentToken.clear();
                }
                result += c;
            }
        }

        cout << result << endl;
    }
    
    return 0;
}