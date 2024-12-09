#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<vector<int>> grid(4, vector<int>(4, 0));
    
    int row = 1, col = 1;
    
    for(char c : s) {
        if(c == '0') {
            cout << row << " " << col << endl;
            cout << row+1 << " " << col << endl;
            row += 2;
        } else {
            cout << row << " " << col << endl;
            cout << row << " " << col+1 << endl;
            col += 2;
        }
    }
    
    return 0;
}