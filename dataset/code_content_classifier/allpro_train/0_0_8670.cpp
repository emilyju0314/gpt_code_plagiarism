#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> display(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            display[i][j] = row[j] - '0';
        }
    }

    int commands = 0;

    for (int i = n-1; i >= 0; i--) {
        int count = 0;
        for (int j = n-1; j >= 0; j--) {
            if ((display[i][j] + count) % 2 == 1) {
                commands++;
                count++;
            }
        }
    }

    cout << commands << endl;

    return 0;
}