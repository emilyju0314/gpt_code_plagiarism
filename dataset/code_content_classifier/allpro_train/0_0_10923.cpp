#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> forest(n);
    for (int i = 0; i < n; i++) {
        cin >> forest[i];
    }

    int max_time = 0;
    vector<string> start_burning(n, string(m, '.'));

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (forest[i][j] == 'X') {
                max_time = max(max_time, 1);
                start_burning[i][j] = 'X';
                start_burning[i-1][j] = 'X';
                start_burning[i+1][j] = 'X';
                start_burning[i][j-1] = 'X';
                start_burning[i][j+1] = 'X';
                start_burning[i-1][j-1] = 'X';
                start_burning[i-1][j+1] = 'X';
                start_burning[i+1][j-1] = 'X';
                start_burning[i+1][j+1] = 'X';
            }
        }
    }

    cout << max_time << endl;
    for (int i = 0; i < n; i++) {
        cout << start_burning[i] << endl;
    }

    return 0;
}