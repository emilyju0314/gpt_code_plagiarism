#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> matrix;

void query(int x0, int y0, int x1, int y1) {
    int result = 0;
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            result ^= matrix[i][j];
        }
    }
    cout << result << endl;
}

void update(int x0, int y0, int x1, int y1, int v) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            matrix[i][j] ^= v;
        }
    }
}

int main() {
    cin >> n >> m;
    matrix = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            query(x0, y0, x1, y1);
        } else {
            int x0, y0, x1, y1, v;
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            update(x0, y0, x1, y1, v);
        }
    }

    return 0;
}