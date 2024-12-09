#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> grid(r, vector<char>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        int min_usages = 0;
        for(int i = 0; i < r; i++) {
            if(grid[i][0] == 'P') {
                min_usages++;
                for(int j = 0; j < c; j++) {
                    if(grid[i][j] == 'A') {
                        grid[i][j] = 'P';
                    } else {
                        grid[i][j] = 'A';
                    }
                }
            }
        }

        bool converted = true;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 'P') {
                    converted = false;
                    break;
                }
            }
        }

        if(!converted) {
            cout << "MORTAL" << endl;
        } else {
            cout << min_usages << endl;
        }
    }

    return 0;
}