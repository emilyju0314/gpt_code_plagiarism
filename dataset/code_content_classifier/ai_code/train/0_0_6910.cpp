#include <iostream>
#include <vector>

using namespace std;

bool checkMatch(int x, int y, vector<vector<int>>& view, vector<vector<int>>& photo) {
    int m = photo.size();
    int n = view.size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (photo[i][j] != -1 && (x + i >= n || y + j >= n || view[x + i][y + j] != photo[i][j])) {
                return false;
            }
        }
    }
    
    return true;
}

void findMatchingArea(int n, int m, vector<vector<int>>& view, vector<vector<int>>& photo) {
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (checkMatch(i, j, view, photo)) {
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
    cout << "NA" << endl;
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<vector<int>> view(n, vector<int>(n));
        vector<vector<int>> photo(m, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> view[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> photo[i][j];
            }
        }

        findMatchingArea(n, m, view, photo);
    }

    return 0;
}  