#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int x = 0, y = 0;
        for(char c : s) {
            if(c == 'L') x--;
            else if(c == 'R') x++;
            else if(c == 'D') y--;
            else if(c == 'U') y++;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}