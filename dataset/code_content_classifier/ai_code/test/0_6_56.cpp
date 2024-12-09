#include <iostream>
#include <vector>
#include <map>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int k, n;
int colors[2005];
ll dp[2005][6][6];
map<int, int> colorMap;

ll solve(int node, int color1, int color2) {
    if(node == (1 << k) - 1) return 1;
    if(dp[node][color1][color2] != -1) return dp[node][color1][color2];

    int nextColor = 1;
    while(colorMap.count(nextColor) > 0) nextColor++;

    ll ans = 0;
    for(int c = 1; c <= 6; c++) {
        if(c != color1 && c != color2) {
            ans = (ans + solve(node + 1, c, colors[node + 1])) % MOD;
        }
    }

    return dp[node][color1][color2] = ans;
}

int main() {
    cin >> k >> n;

    for(int i = 0; i < n; i++) {
        int node;
        string color;
        cin >> node >> color;

        if(color == "white") colors[node - 1] = 1;
        else if(color == "yellow") colors[node - 1] = 2;
        else if(color == "green") colors[node - 1] = 3;
        else if(color == "blue") colors[node - 1] = 4;
        else if(color == "red") colors[node - 1] = 5;
        else if(color == "orange") colors[node - 1] = 6;

        colorMap[node - 1] = colors[node - 1];
    }

    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, 0, colors[0]);
    
    cout << ans << endl;

    return 0;
}