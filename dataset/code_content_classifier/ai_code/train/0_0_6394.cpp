#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    char flag[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> flag[i][j];
        }
    }
    
    int repaint = 0;
    
    // Repaint rows to make top white
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i < N/3 && flag[i][j] != 'W') {
                repaint++;
            } else if (i >= N/3 && i < 2*N/3 && flag[i][j] != 'B') {
                repaint++;
            } else if (i >= 2*N/3 && flag[i][j] != 'R') {
                repaint++;
            }
        }
    }
    
    cout << repaint << endl;
    
    return 0;
}