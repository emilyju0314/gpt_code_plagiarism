#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    vector<vector<char>> result(2*n-1, vector<char>(2*n-1, '.'));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int dx = -1, dy = -1;
    bool found = false;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 'o') {
                if(i > 0 && board[i-1][j] == 'x') {
                    dx = 0; dy = -1;
                    found = true;
                } else if (j > 0 && board[i][j-1] == 'x') {
                    dx = -1; dy = 0;
                    found = true;
                } else if (i < n-1 && board[i+1][j] == 'x') {
                    dx = 0; dy = 1;
                    found = true;
                } else if (j < n-1 && board[i][j+1] == 'x') {
                    dx = 1; dy = 0;
                    found = true;
                }
            }
            
            if(found) break;
        }
        if(found) break;
    }

    if(dx == -1 && dy == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        int center = n-1;
        result[center][center] = 'o';
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'x') {
                    result[center+i][center+j] = 'x';
                }
            }
        }

        for(int i=0; i<2*n-1; i++) {
            for(int j=0; j<2*n-1; j++) {
                cout << result[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}