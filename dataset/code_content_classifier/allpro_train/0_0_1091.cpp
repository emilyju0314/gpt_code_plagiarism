#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> depot(n);
    vector<int> rows(n, 0), cols(m, 0);
    
    for(int i = 0; i < n; i++) {
        cin >> depot[i];
        for(int j = 0; j < m; j++) {
            if(depot[i][j] == '*') {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rows[i] + cols[j] - (depot[i][j] == '*') == max(rows[i], cols[j])) {
                cout << "YES" << endl;
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}