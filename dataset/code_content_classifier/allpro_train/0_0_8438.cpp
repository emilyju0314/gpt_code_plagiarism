#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    int tp, tu, td;
    cin >> tp >> tu >> td;

    vector<vector<int>> heights(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }

    int min_diff = INT_MAX;
    int ul_row, ul_col, lr_row, lr_col;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = i+2; k < n; k++) {
                for(int l = j+2; l < m; l++) {
                    int total_time = 0;
                    for(int a = i; a <= k; a++) {
                        for(int b = j; b <= l; b++) {
                            if(a == i && b == j) {
                                total_time += tp; // starting point
                            } else {
                                int diff = heights[a][b] - heights[a-1][b];
                                if(diff < 0) {
                                    total_time += td;
                                } else if(diff > 0) {
                                    total_time += tu;
                                } else {
                                    total_time += tp;
                                }
                            }
                        }
                    }
                    int time_diff = abs(total_time - t);
                    if(time_diff < min_diff) {
                        min_diff = time_diff;
                        ul_row = i+1;
                        ul_col = j+1;
                        lr_row = k+1;
                        lr_col = l+1;
                    }
                }
            }
        }
    }

    cout << ul_row << " " << ul_col << " " << lr_row << " " << lr_col << endl;

    return 0;
}