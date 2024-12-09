#include <iostream>
#include <string>
#include <vector>

using namespace std;

string moveBall(string &board, int a, int b, int c, int d) {
    int W = board.find('/');
    vector<string> rows;
    
    while (board.find('/') != string::npos) {
        rows.push_back(board.substr(0, W));
        board = board.substr(W + 1);
    }
    rows.push_back(board);
    
    if (rows[a][b] != 'b' || rows[c][d] != '.') {
        return "";
    }
    
    rows[a][b] = '.';
    rows[c][d] = 'b';
    
    string newBoard = "";
    
    for (int i = 0; i < rows.size(); i++) {
        newBoard += rows[i] + '/';
    }
    
    return newBoard.substr(0, newBoard.size() - 1);
}

int main() {
    string S;
    int a, b, c, d;
    
    while (getline(cin, S)) {
        if (S == "#") {
            break;
        }
        
        cin >> a >> b >> c >> d;
        
        cout << moveBall(S, a, b, c, d) << endl;
    }
    
    return 0;
}