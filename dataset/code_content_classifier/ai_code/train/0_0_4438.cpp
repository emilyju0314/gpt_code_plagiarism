#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int maxHeight = 1;
        queue<int> q;
        q.push(a[0]);

        int curMaxHeight = 1;
        for(int i = 1; i < n; i++) {
            // if a[i] is child of a[i-1]
            if (a[i] > a[i-1]) {
                q.push(a[i]);
                curMaxHeight++;
                maxHeight = max(maxHeight, curMaxHeight);
            } else {
                q.pop(); // go up one level
                curMaxHeight--;
                q.push(a[i]);
                curMaxHeight++;
            }
        }
        
        cout << maxHeight << endl;
    }
    
    return 0;
}