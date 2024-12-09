#include <iostream>
#include <string>

using namespace std;

bool canReachPlanet(int px, int py, string s) {
    int x = 0, y = 0;
    for(char c : s) {
        if(c == 'U') y++;
        else if(c == 'D') y--;
        else if(c == 'R') x++;
        else if(c == 'L') x--;
    }
    
    int diffx = px - x;
    int diffy = py - y;
    
    int cntU = 0, cntD = 0, cntR = 0, cntL = 0;
    
    for(char c : s) {
        if(c == 'U') cntU++;
        else if(c == 'D') cntD++;
        else if(c == 'R') cntR++;
        else if(c == 'L') cntL++;
    }
    
    return (diffx <= cntR && diffx >= -cntL && diffy <= cntU && diffy >= -cntD);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int px, py;
        string s;
        cin >> px >> py >> s;
        
        if(canReachPlanet(px, py, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}