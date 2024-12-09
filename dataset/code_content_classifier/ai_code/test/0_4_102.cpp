#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> getStartingCell(int n, int m, string s) {
    int minR = 1, maxR = n, minC = 1, maxC = m;
    
    for(char command : s) {
        if(command == 'L') {
            maxC = min(maxC - 1, m);
        } else if(command == 'R') {
            minC = max(minC + 1, 1);
        } else if(command == 'U') {
            maxR = min(maxR - 1, n);
        } else if(command == 'D') {
            minR = max(minR + 1, 1);
        }
    }
    
    return {minR, minC};
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        string s;
        cin >> s;
        
        pair<int, int> result = getStartingCell(n, m, s);
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}