#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    
    // Check if there is a statue in Maria's initial position
    if (board[7][0] == 'S') {
        cout << "LOSE" << endl;
        return 0;
    }
    
    // Check if Maria can reach Anna's position without encountering a statue
    for (int i = 6; i >= 0; i--) {
        int j = 1;
        if (board[i][j] == 'S') {
            cout << "WIN" << endl;
            return 0;
        }
    }
    
    // If Maria cannot reach Anna's position without encountering a statue, statues win
    cout << "LOSE" << endl;
    
    return 0;
}