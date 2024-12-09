#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> island(n);
    for(int i = 0; i < n; i++) {
        cin >> island[i];
    }

    int ans = 0;

    for(int i = 0; i < n-1; i++) {
        if(island[i][m-1] == '.') {
            ans++;
        }
    }

    for(int j = 0; j < m-1; j++) {
        if(island[n-1][j] == '.') {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}