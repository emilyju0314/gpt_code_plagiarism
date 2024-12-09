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

    int centerRow, centerCol;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(table[i][j] == 'B') {
                centerRow = i + 1;
                centerCol = j + 1;
            }
        }
    }

    cout << centerRow << " " << centerCol << endl;

    return 0;
}