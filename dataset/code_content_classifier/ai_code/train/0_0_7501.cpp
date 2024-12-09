#include <iostream>
#include <string>

using namespace std;

int main() {
    string movements;
    cin >> movements;
    
    int x = 0, y = 0;
    for(char move : movements) {
        if(move == 'L') x--;
        else if(move == 'R') x++;
        else if(move == 'U') y++;
        else if(move == 'D') y--;
    }
    
    if(x == 0 && y == 0) {
        cout << "OK" << endl;
    } else {
        cout << "BUG" << endl;
    }
    
    return 0;
}