#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4e6 + 5;

int n, m;
vector<vector<int>> ft(MAXN, vector<int>(MAXN, 0));

void add(int x, int y, int v) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= m; j += j & -j) {
            ft[i][j] += v;
        }
    }
}

int get(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            sum += ft[i][j];
        }
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

int main() {
    int w;
    cin >> n >> m >> w;

    while (w--) {
        int type;
        cin >> type;

        if (type == 0) {
            int x1, y1, x2, y2, v;
            cin >> x1 >> y1 >> x2 >> y2 >> v;
            add(x1, y1, v);
            add(x2 + 1, y1, -v);
            add(x1, y2 + 1, -v);
            add(x2 + 1, y2 + 1, v);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int dima = query(x1, y1, x2, y2);
            int inna = query(1, 1, n, m) - dima;
            cout << dima - inna << "\n";
        }
    }

    return 0;
}