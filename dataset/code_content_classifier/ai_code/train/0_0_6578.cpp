#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    bool possible = true;
    for(int i = 1; i <= n; i++) {
        if(a[i] > n-i || b[i] > i-1) {
            possible = false;
            break;
        }
        for(int j = 1; j <= a[i]; j++) {
            graph[n-j+1][i] = 1;
        }
        for(int j = 1; j <= b[i]; j++) {
            graph[i][j] = 1;
        }
    }

    if(!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << graph[i][j] << (j == n ? "\n" : " ");
            }
        }
    }

    return 0;
}