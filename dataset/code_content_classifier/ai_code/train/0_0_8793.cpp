#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> puzzle(n, vector<int>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> puzzle[i][j];
        }
    }

    int t;
    cin >> t;

    while(t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int answer = 0;
        for(int i=x1-1; i<x2; i++) {
            for(int j=y1-1; j<y2; j++) {
                int side = min(i-x1+1, j-y1+1);
                if(puzzle[i][j] == 1) {
                    while(side > answer) {
                        bool valid = true;
                        for(int x=i-side+1; x<=i; x++) {
                            for(int y=j-side+1; y<=j; y++) {
                                if(puzzle[x][y] != 1) {
                                    valid = false;
                                    break;
                                }
                            }
                            if(!valid) break;
                        }
                        if(valid) answer = side;
                        side--;
                    }
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}