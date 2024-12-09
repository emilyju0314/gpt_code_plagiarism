#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> chessboard(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> chessboard[i][j];
        }
    }
    
    long long max_money = 0;
    int x1, y1, x2, y2;
    
    // Find the maximum amount of dollars Gargari will get by trying all possible bishop placements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    if(i != k || j != l) {
                        long long money = chessboard[i][j] + chessboard[k][l];
                        money -= (i-j == k-l || i+j == k+l); // subtract if the cells are on the same diagonal
                        if(money > max_money) {
                            max_money = money;
                            x1 = i+1;
                            y1 = j+1;
                            x2 = k+1;
                            y2 = l+1;
                        }
                    }
                }
            }
        }
    }
    
    cout << max_money << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    
    return 0;
}