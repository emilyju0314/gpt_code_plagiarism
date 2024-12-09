#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> receivers(n);
    for (int i = 0; i < n; i++) {
        cin >> receivers[i];
    }

    vector<vector<char>> maze(n, vector<char>(n, '.'));

    int count = 0;
    for (int i = 0; i < n; i++) {
        int laser = i;
        while (receivers[laser] != i + 1) {
            maze[i][laser] = '/';
            count++;
            laser = receivers[laser] - 1;
        }
    }

    cout << count << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}