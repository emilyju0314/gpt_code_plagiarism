#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for(int i = 0; i < n; i++) {
        cin >> table[i];
    }

    vector<vector<char>> niceTable(n, vector<char>(m));
    char possibleChars[] = {'A', 'G', 'C', 'T'};
    int idx = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vector<char> chars = {possibleChars[(idx + 0) % 4], possibleChars[(idx + 1) % 4], possibleChars[(idx + 2) % 4], possibleChars[(idx + 3) % 4]};
            if(i % 2 == 1) {
                swap(chars[0], chars[1]);
            }
    
            if(j % 2 == 1) {
                swap(chars[0], chars[2]);
                swap(chars[1], chars[3]);
            }
    
            niceTable[i][j] = chars[0];
    
            if(table[i][j] != niceTable[i][j]) {
                idx++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << niceTable[i][j];
        }
        cout << endl;
    }

    return 0;
}