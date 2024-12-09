#include <bits/stdc++.h>
using namespace std;

int query1(int a, int b) {
    cout << 1 << " " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

int query2(int x, int k, vector<int>& s) {
    cout << 2 << " " << x << " " << k;
    for (int i = 0; i < k; i++) {
        cout << " " << s[i];
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int direction = query1(i, j);
                    graph[i][j] = direction;
                }
            }
        }

        vector<vector<int>> answer(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            vector<int> s;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    s.push_back(j);
                }
            }
            int result = query2(i, n - 1, s);
            if (result == 1) {
                answer[i] = vector<int>(n, 1);
            }
        }

        cout << 3 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << answer[i][j];
            }
            cout << endl;
        }
        cout.flush();

        int verdict;
        cin >> verdict;
        if (verdict == -1) {
            break;
        }
    }

    return 0;
}