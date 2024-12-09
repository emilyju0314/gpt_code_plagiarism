#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    for(char c : s) {
        if(c == 'U') {
            y++;
        } else if(c == 'D') {
            y--;
        } else if(c == 'L') {
            x--;
        } else if(c == 'R') {
            x++;
        }
    }
    
    if((x == a && y == b) || (s.find('L') == string::npos && s.find('R') == string::npos && x == a) || 
       (s.find('U') == string::npos && s.find('D') == string::npos && y == b)) {
        cout << "Yes\n";
    } else if((x != 0 || y != 0) && ((a-x) % x == 0) && ((b-y) % y == 0) && ((a-x) / x == (b-y) / y)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}