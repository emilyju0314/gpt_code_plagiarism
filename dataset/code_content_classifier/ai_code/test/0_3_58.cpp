#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canCompleteLevel(int n, const vector<string>& level) {
    int x = 0, y = 0;
    for(int j = 0; j < n - 1; j++) {
        if(level[1][j] == '1') {
            if(level[0][j + 1] == '0' && level[1][j + 1] == '0') {
                x = 1;
                y = j + 1;
            } else if(level[0][j] == '0' && level[1][j] == '0') {
                x = 0;
                y = j;
            } else {
                return false;
            }
        }
    }
    
    if(x == 1 && y == n - 1) {
        return true;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<string> level(2);
        cin >> level[0] >> level[1];
        
        if(canCompleteLevel(n, level)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}