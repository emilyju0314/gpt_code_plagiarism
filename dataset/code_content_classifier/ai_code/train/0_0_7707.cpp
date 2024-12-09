#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> boardA(n, vector<char>(m));
    vector<vector<char>> boardB(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> boardA[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> boardB[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(boardA[i][j] != boardB[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}