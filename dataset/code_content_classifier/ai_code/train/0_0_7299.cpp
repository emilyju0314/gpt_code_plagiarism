#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> flag(n);
    vector<vector<char>> newFlag(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        cin >> flag[i];
    }

    int repaints = 0;

    // Repaint each row according to the restrictions
    for(int i = 0; i < n; i++) {
        char color1 = 'a', color2 = 'b';
        for(int j = 0; j < m; j++) {
            if(j % 2 == 0) {
                if(flag[i][j] == color1) {
                    repaints++;
                }
                newFlag[i][j] = color1;
            } else {
                if(flag[i][j] == color2) {
                    repaints++;
                }
                newFlag[i][j] = color2;
            }
        }
    }

    cout << repaints << endl;

    // Output the new flag
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << newFlag[i][j];
        }
        cout << endl;
    }

    return 0;
}