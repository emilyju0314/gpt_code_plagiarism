#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<vector<int>> table(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    int max_sum = 0;
    int count = 0;
    
    for (int i = r; i < n - r; i++) {
        for (int j = r; j < m - r; j++) {
            for (int x = r; x < n - r; x++) {
                for (int y = r; y < m - r; y++) {
                    if (i != x || j != y) {
                        int sum = 0;
                        for (int dx = -r; dx <= r; dx++) {
                            for (int dy = -r; dy <= r; dy++) {
                                if ((dx*dx) + (dy*dy) <= (r*r)) {
                                    sum += table[i+dx][j+dy];
                                }
                            }
                        }
                        for (int dx = -r; dx <= r; dx++) {
                            for (int dy = -r; dy <= r; dy++) {
                                if ((dx*dx) + (dy*dy) <= (r*r)) {
                                    sum += table[x+dx][y+dy];
                                }
                            }
                        }
                        if (sum > max_sum) {
                            max_sum = sum;
                            count = 1;
                        } else if (sum == max_sum) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    
    cout << max_sum << " " << count << endl;

    return 0;
}