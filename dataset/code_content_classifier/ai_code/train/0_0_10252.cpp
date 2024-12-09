#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> board(8);
    bool valid = true;
    
    for(int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < 8; i++) {
        int countW = 0, countB = 0;
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'W') countW++;
            else countB++;
        }
        if(countW != 4 || countB != 4) {
            valid = false;
            break;
        }
    }

    if(valid) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}