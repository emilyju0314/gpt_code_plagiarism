#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<char>> seats(M, vector<char>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> seats[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (seats[i][j] == 'o' && 
                (j == 0 ||
                (j > 0 && seats[i][j-1] != 'o') ||
                (j < N-1 && seats[i][j+1] != 'o') ||
                (i > 0 && seats[i-1][j] != 'o') ||
                (i < M-1 && seats[i+1][j] != 'o'))) {
                
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}