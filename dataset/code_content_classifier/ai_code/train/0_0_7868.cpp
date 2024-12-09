#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<int> upLine(n);
        vector<int> downLine(m);
        
        for (int i = 0; i < n; i++) {
            cin >> upLine[i];
        }
        
        for (int i = 0; i < m; i++) {
            cin >> downLine[i];
        }
        
        int maxInterval = 0;
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            int interval = abs(upLine[i] - downLine[j]);
            maxInterval = max(maxInterval, interval);
            
            if (upLine[i] < downLine[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        cout << maxInterval << endl;
    }
    
    return 0;
}