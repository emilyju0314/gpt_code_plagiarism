#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
    int n,m,l,k,a,h;
    while (cin>>n>>m>>l>>k>>a>>h && n) {
        vector<int> d(l);
        for (int i = 0; i < l; i++) cin >> d[i];
        l += 2;
        d.push_back(a);
        d.push_back(h);
        
        vector<vector<int> > e(n, vector<int>(n, 101010));
        for (int i = 0; i < n; i++) e[i][i] = 0;
        for (int i = 0; i < k; i++) {
            int x,y,z;
            cin>>x>>y>>z;
            e[x][y] = z;
            e[y][x] = z;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    e[i][j] = min(e[i][j], e[i][k]+e[k][j]);
                    e[j][i] = e[i][j];
                }
            }
        }
        for (int i = 0; i < l-1; i++) {
            for (int j = i+1; j < l; j++) {
                int x = d[i];
                int y = d[j];
                if (e[x][y] > m) e[x][y] = 101010, e[y][x] = 101010;
            }
        }
        
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    int x = d[i];
                    int y = d[j];
                    int z = d[k];
                    e[x][y] = min(e[x][y], e[x][z]+e[z][y]);
                    e[y][x] = e[x][y];
                }
            }
        }
        
        if (e[a][h] >= 101010) cout << "Help!" << endl;
        else if (e[a][h] > m) cout << e[a][h]*2-m << endl;
        else cout << e[a][h] << endl;
    }
}