#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string commands;
    
    cin >> n;
    cin >> commands;
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int x = 0, y = 0;
        for(int j = i; j < n; j++) {
            if(commands[j] == 'U') y++;
            else if(commands[j] == 'D') y--;
            else if(commands[j] == 'L') x--;
            else if(commands[j] == 'R') x++;
            
            if(x == 0 && y == 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;

    return 0;
}