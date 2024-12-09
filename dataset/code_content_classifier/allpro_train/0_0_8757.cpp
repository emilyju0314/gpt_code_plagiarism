#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSequence(string s) {
    int x = 0, y = 0;
    for(char& c : s) {
        if(c == 'L') x--;
        else if(c == 'R') x++;
        else if(c == 'U') y++;
        else if(c == 'D') y--;
    }
    
    return x == 0 && y == 0;
}

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        string s;
        cin >> s;
        
        vector<char> valid;

        for(char& c : s) {
            if(c == 'L' && count(s.begin(), s.end(), 'L') > 0 && count(s.begin(), s.end(), 'R') > 0) {
                valid.push_back(c);
            } else if(c == 'R' && count(s.begin(), s.end(), 'R') > 0 && count(s.begin(), s.end(), 'L') > 0) {
                valid.push_back(c);
            } else if(c == 'U' && count(s.begin(), s.end(), 'U') > 0 && count(s.begin(), s.end(), 'D') > 0) {
                valid.push_back(c);
            } else if(c == 'D' && count(s.begin(), s.end(), 'D') > 0 && count(s.begin(), s.end(), 'U') > 0) {
                valid.push_back(c);
            }
        }

        cout << valid.size() << endl;
        for(char& c : valid) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}