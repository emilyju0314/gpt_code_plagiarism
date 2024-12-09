#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads[i] = make_pair(a, b);
    }
    
    cout << min(k, 2) << endl; // Output at most 2 options
    
    for (int i = 0; i < min(k, 2); i++) {
        string option = "";
        for (int j = 0; j < m; j++) {
            if (j % 2 == i) option += '1';
            else option += '0';
        }
        cout << option << endl;
    }
    
    return 0;
}