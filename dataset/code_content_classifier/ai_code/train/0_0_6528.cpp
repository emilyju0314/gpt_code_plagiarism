#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = k + 2;
    cout << n << endl;

    vector<vector<char>> graph(n, vector<char>(n, 'N'));

    for (int i = 1; i < n - 1; i++) {
        graph[0][i] = 'Y';
        graph[i][n-1] = 'Y';
    }

    graph[1][n-2] = 'Y';
    
    int count = 1;
    for (int i = 1; count < k; i++) {
        for (int j = 1; j < n - 1 && count < k; j++) {
            if (graph[i][j] == 'N' && i != j) {
                graph[i][j] = 'Y';
                count++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}