#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int ans = 0;
    
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = j1; j2 < m; j2++) {
                    set<int> elements;
                    bool is_inhomogeneous = true;
                    
                    for (int i = i1; i <= i2; i++) {
                        for (int j = j1; j <= j2; j++) {
                            if (elements.count(matrix[i][j]) > 0) {
                                is_inhomogeneous = false;
                                break;
                            }
                            elements.insert(matrix[i][j]);
                        }
                        if (!is_inhomogeneous) {
                            break;
                        }
                    }
                    
                    if (is_inhomogeneous) {
                        int area = (i2 - i1 + 1) * (j2 - j1 + 1);
                        ans = max(ans, area);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}