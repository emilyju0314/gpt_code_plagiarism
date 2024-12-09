#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> colors(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> colors[i][j];
        }
    }

    int result = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                unordered_set<int> unique_colors;
                bool valid = true;
                for(int x = 0; x < k; x++) {
                    for(int y = 0; y < k; y++) {
                        unique_colors.insert(colors[i + x][j + y]);
                        if(unique_colors.size() > q) {
                            valid = false;
                            break;
                        }
                    }
                    if(!valid) break;
                }
                if(valid) result++;
            }
        }
        cout << result << endl;
        result = 0;
    }

    return 0;
}