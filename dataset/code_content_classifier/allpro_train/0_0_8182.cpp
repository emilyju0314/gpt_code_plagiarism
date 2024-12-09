#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> feature(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> feature[i][j];
        }
    }

    int operations = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(feature[i][j] == 'W') {
                operations++;
            } else {
                operations--;
            }
        }
    }

    cout << abs(operations) << endl;

    return 0;
}