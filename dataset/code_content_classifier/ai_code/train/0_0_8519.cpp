#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;

    int x = 0, y = 0;
    for(char c : s) {
        if(c == 'U') y++;
        else if(c == 'D') y--;
        else if(c == 'L') x--;
        else if(c == 'R') x++;
    }

    if((x == 0 && y == 0) || (a == 0 && b == 0)) {
        if(a == x && b == y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        int moveX = (a - x) / x;
        int moveY = (b - y) / y;
        
        if((a - x) % x == 0 && (b - y) % y == 0 && moveX >= 0 && moveY >= 0 && moveX % 2 == moveY % 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}