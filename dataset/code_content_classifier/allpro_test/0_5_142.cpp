#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> joy(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> joy[i][j];
            }
        }

        vector<int> minJoyPerFriend(n, INT_MAX);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                minJoyPerFriend[j] = min(minJoyPerFriend[j], joy[i][j]);
            }
        }

        sort(minJoyPerFriend.begin(), minJoyPerFriend.end());

        cout << minJoyPerFriend[n-2] << endl;
    }

    return 0;
}