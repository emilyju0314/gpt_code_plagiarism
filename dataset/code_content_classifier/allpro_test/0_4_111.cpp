#include <iostream>
#include <vector>
#include <cstring>
#define MOD 998244353
using namespace std;

int n, k;
int c[2005], b[2005];
int f[2005][105][2]; 

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    memset(f, 0, sizeof(f));
    f[0][k][1]=1;
    for(int i = 1; i <= n; i++) {
        for(int x = 0; x <= n; x++) {
            for(int y = 0; y <= 2*k; y++) {
                for(int z = 0; z <= 1; z++) {
                    if(!f[x][y][z])
                        continue;
                    for(int j = 0; j <= n; j++) {
                        if(z == 1 && j > b[i])
                            break;
                        int t1 = b[i] - 1;
                        int t2 = b[i];
                        if(j != 0) {
                            t1 = 0;
                        }
                        if(j == 0) {
                            t2 += k;
                        }
                        (f[x + j][max(y - t1, 0)][j > b[i] ? 1 : j < b[i] ? 0 : z] += f[x][y][z]) %= MOD;
                    }
                }
            }
        }
        
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 2*k; j++)
            (ans += f[n][j][0] + f[n][j][1]) %= MOD;
    cout << ans << endl;

    return 0;
}