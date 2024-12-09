#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        int x = i;
        int y = i;
        for(int j = 0; j < p[i]; j++) {
            grid[x][y] = p[i];
            x++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}