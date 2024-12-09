#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool magic = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i] || i == j) {
                magic = false;
                break;
            }
        }
        if(!magic) {
            break;
        }
    }

    if(magic) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(matrix[i][j] != max(matrix[i][k], matrix[j][k])) {
                        magic = false;
                        break;
                    }
                }
                if(!magic) {
                    break;
                }
            }
            if(!magic) {
                break;
            }
        }
    }

    if(magic) {
        cout << "MAGIC" << endl;
    } else {
        cout << "NOT MAGIC" << endl;
    }

    return 0;
}