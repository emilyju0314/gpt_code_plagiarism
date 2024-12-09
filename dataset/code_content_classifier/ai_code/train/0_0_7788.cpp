#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dist[20][20];

int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    int ans = INT_MAX;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int mask = 1;
    int pos = 0;
    int ans = tsp(mask, pos);

    cout << ans << endl;

    return 0;
}