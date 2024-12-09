#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> pasture(R, vector<char>(C));
    bool possible = true;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> pasture[i][j];
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(pasture[i][j] == 'W') {
                if(i-1 >= 0 && pasture[i-1][j] == 'S') {
                    possible = false;
                }
                if(i+1 < R && pasture[i+1][j] == 'S') {
                    possible = false;
                }
                if(j-1 >= 0 && pasture[i][j-1] == 'S') {
                    possible = false;
                }
                if(j+1 < C && pasture[i][j+1] == 'S') {
                    possible = false;
                }
            }
        }
    }

    if(!possible) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(pasture[i][j] == '.') {
                    cout << "D";
                } else {
                    cout << pasture[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}