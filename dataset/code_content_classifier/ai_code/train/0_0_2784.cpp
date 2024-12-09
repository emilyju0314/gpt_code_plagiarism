#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> minPos(n+1, 1);
    vector<int> maxPos(n+1, 1);

    for(int i = 0; i < m; i++) {
        int cur = a[i];
        maxPos[cur] = max(maxPos[cur], 1);

        for(int j = 1; j <= n; j++) {
            if(j != cur) {
                minPos[j]++;
                maxPos[j]++;
            }
        }

        minPos[cur] = 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << minPos[i] << " " << maxPos[i] << endl;
    }

    return 0;
}