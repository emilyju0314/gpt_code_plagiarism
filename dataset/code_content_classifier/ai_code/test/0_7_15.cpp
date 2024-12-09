#include <iostream>
#include <vector>

using namespace std;

bool isValidTick(vector<string>& field, int i, int j, int k) {
    int n = field.size();
    int m = field[0].size();
    
    if (field[i][j] == '.') {
        return false;
    }
    
    int d = 0;
    while (i+d < n && i-d >= 0 && j+d < m && j-d >= 0) {
        if (field[i+d][j+d] == '.' || field[i-d][j-d] == '.') {
            break;
        }
        bool isValid = true;
        for (int h = 0; h <= d; h++) {
            if (field[i-h][j+h] != '*' || field[i+h][j+h] != '*') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            return true;
        }
        d++;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> field(n);
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }
        
        bool canBeObtained = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValidTick(field, i, j, k)) {
                    continue;
                } else {
                    canBeObtained = false;
                    break;
                }
            }
            if (!canBeObtained) {
                break;
            }
        }
        
        if (canBeObtained) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}