#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli inf = 1e18;

bool is_digit(string &s){
    if(s.length()>=2u and s[0]=='0') return false;
    for(char c: s){
        if(!('0'<=c and c<='9')) return false;
    }
    return true;
}

int main(){
    lli n;
    string s;
    cin >> n >> s;
    s += "+";
    int m = s.length();
    // dp[i][j][k] = (s[i::i+j]をk文字置換して"xxxx+"の形式にしたときの最小の評価値)
    vector<vector<vector<lli>>> dp_pre(m, vector<vector<lli>>(12, vector<lli>(12, inf)));
    for(int i=0; i<m; i++){
        for(int j=1; j<=10; j++){
            if(i+j >= m) break;
            string sub = s.substr(i, j);
            int count = (s[i+j]=='+')? 0: 1;
            for(int k=0; k<j; k++){
                if(sub[k]=='+'){
                    if(k==0 and j!=1) sub[k] = '1';
                    else sub[k] = '0';
                    count++;
                }
            }
            for(int nrep=0; nrep<=j; nrep++){
                if(is_digit(sub)){
                    dp_pre[i][j+1][count] = min(dp_pre[i][j+1][count], stoll(sub));
                }
                if(nrep == j) break;
                char repc = (nrep==0 and j!=1)? '1': '0';
                if(sub[nrep] != repc){
                    sub[nrep] = repc;
                    count++;
                }
                
            }
        }
    }
    vector<vector<lli>> dp(m+1, vector<lli>(m+1, inf));
    dp[0][0] = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m+1; j++){
            if(dp[i][j] == inf) continue;
            for(int k=0; k<12; k++){
                for(int l=0; l<12; l++){
                    if(i+k>m or j+l>m) continue;
                    dp[i+k][j+l] = min(dp[i+k][j+l], dp[i][j]+dp_pre[i][k][l]);
                }
            }
        }
    }
    int ans = -1;
    for(int i=0; i<m+1; i++){
        if(dp[m][i] <= n){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

