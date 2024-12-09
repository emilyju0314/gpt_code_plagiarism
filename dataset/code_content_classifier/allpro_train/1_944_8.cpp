#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <utility>
using namespace std;

constexpr int varc = 625;
pair<bool, bitset<varc>> solve_linear_eq_F2(vector<bitset<varc+1>> g, int varnum){
    int n = g.size();
    for(int i=0, p=0; i<n and p<varc+1; i++, p++){
        for(int j=i+1; j<n; j++){
            if(g[j][p] == 1){
                swap(g[i], g[j]);
                break;
            }
        }
        if(g[i][p] == 0){
            i--;
            continue;
        }
        for(int j=i-1; j<n; j++){
            if(j != i and g[j][p] == 1){
                g[j] ^= g[i];
            }
        }
    }
    
    bool has_sol = true;
    bitset<varc> res, decided;
    for(int i=n-1; i>=0; i--){
        int right = g[i][varnum];
        vector<int> vars;
        for(int j=0; j<varnum; j++){
            if(g[i][j]==1){
                if(decided[j]==1 and res[j]==1){
                    right ^= 1;
                }else if(decided[j]==0){
                    vars.push_back(j);
                }
            }
        }
        for(int j: vars){
            res[j] = 0;
            decided[j] = 1;
        }
        if(right==1){
            if(vars.empty()){
                has_sol = false;
                break;
            }else{
                res[vars[0]] = 1;
            }
        }
    }
    return make_pair(has_sol, res);
}

int main(){
    while(1){
        int m,n,d;
        cin >> m >> n >> d;
        if(m == 0) break;
        
        vector<vector<int>> s(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> s[i][j];
            }
        }
        vector<bitset<varc+1>> g(n*m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                g[i*m+j][i*m+j] = 1;
                g[i*m+j][n*m] = s[i][j];
                for(int k=0; k<n; k++){
                    for(int l=0; l<m; l++){
                        if(abs(i-k) + abs(j-l) == d){
                            g[i*m+j][k*m+l] = 1;
                        }
                    }
                }
            }
        }     
        auto ret = solve_linear_eq_F2(g, n*m);
        cout << ret.first << endl;
    }
    return 0;
}

