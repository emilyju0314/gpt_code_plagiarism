#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<string> strings(R);
    for (int i = 0; i < R; i++) {
        cin >> strings[i];
    }
    
    int maxPoints = 0;
    
    for (int i = 0; i < R; i++) {
        string currentString = strings[i];
        
        for (int j = 0; j < currentString.length(); j++) {
            char currentChar = currentString[j];
            
            int up, down, left, right;
            up = down = left = right = 0;
            
            for (int k = i-1; k >= 0 && strings[k][j] == currentChar; k--) {
                up++;
            }
            for (int k = i+1; k < R && strings[k][j] == currentChar; k++) {
                down++;
            }
            for (int k = j-1; k >= 0 && strings[i][k] == currentChar; k--) {
                left++;
            }
            for (int k = j+1; k < C && strings[i][k] == currentChar; k++) {
                right++;
            }
            
            int currentPoints = up + down + left + right;
            maxPoints += currentPoints;
        }
    }
    
    cout << maxPoints << endl;
    
    return 0;
}