#include <iostream>
#include <string>

using namespace std;

string lexicographicallySmallestString(string s) {
    string result = "";
    int countZero = 0, countOne = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            countZero++;
        } else {
            countOne++;
        }
    }

    if (countZero == 0 || countOne == 0) {
        return s;
    }

    result += "0";
    for (int i = 0; i < countZero; i++) {
        result += "0";
    }
    for (int i = 0; i < countOne; i++) {
        result += "1";
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        
        cout << lexicographicallySmallestString(s) << endl;
    }

    return 0;
}