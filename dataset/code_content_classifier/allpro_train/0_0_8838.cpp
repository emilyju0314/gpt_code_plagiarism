#include <iostream>
#include <vector>

using namespace std;

bool canTransform(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] != B[j][i]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }

    if(canTransform(A, B)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}