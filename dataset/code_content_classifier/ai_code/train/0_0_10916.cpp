#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int x;
    cin >> x;

    vector<vector<int>> c(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c[i][j] = a[i] * b[j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    sum += c[k][l];
                    if(sum <= x) {
                        ans = max(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}