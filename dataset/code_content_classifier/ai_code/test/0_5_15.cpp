#include <iostream>
#include <vector>

using namespace std;

bool canBeObtained(int n, int m, int k, vector<string>& field) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == '*') {
                if(i + k > n || j - k < 0 || j + k >= m) {
                    return false;
                }
                for(int h = 0; h <= k; h++) {
                    if(field[i-h][j-h] != '*' || field[i-h][j+h] != '*') {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> field(n);
        
        for(int i = 0; i < n; i++) {
            cin >> field[i];
        }

        if(canBeObtained(n, m, k, field)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}