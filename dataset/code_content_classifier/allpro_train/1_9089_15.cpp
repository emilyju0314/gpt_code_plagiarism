#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;





int main(){
    ll n,m,s,t;
    while(cin>>n>>m>>s>>t){
        if(n==0){break;}
        s--; t--;
        vector<vector<bool>> A(n,vector<bool>(n,false));
        vector<vector<bool>> B(n,vector<bool>(n,false));
        vector<vector<bool>> C(n,vector<bool>(n,false));
        vector<vector<bool>> D(n,vector<bool>(n,false));
        vector<vector<bool>> F(n,vector<bool>(n,false));
        queue<pair<pll,ll>> Q;
        vector<vector<ll>> E1(n);
        vector<vector<ll>> E2(n);
        vector<vector<pair<ll,char>>> E3(n);
        vector<vector<ll>> E4(n);
        set<pair<pll,char>> S;
        for(int i=0;i<m;i++){
            ll a,b;
            char c;
            cin>>a>>b>>c;
            a--; b--;
            S.insert({{a,b},c});
        }
        for(auto I=S.begin();I!=S.end();++I){
            if(I->second=='a'){
                Q.push({{I->first.F,I->first.S},0});
                A[I->first.F][I->first.S]=true;
            }
            else if(I->second=='('){
                E1[I->first.S].push_back(I->first.F);
            }
            else if(I->second=='['){
                E2[I->first.S].push_back(I->first.F);
            }
            else{
                E3[I->first.F].push_back({I->first.S,I->second});
            }
            if(I->second=='*' || I->second=='+'){
                E4[I->first.S].push_back(I->first.F);
            }
        }
        while(!Q.empty()){
            pair<pll,ll> W=Q.front(); Q.pop();
            pll w=W.F;
            if(W.S==0){
                for(auto &I:E3[w.S]){
                    if(I.S==')'){
                        if(!B[w.F][I.F]){B[w.F][I.F]=true; Q.push({{w.F,I.F},1});}
                    }
                    else if(I.S==']'){
                        if(!C[w.F][I.F]){C[w.F][I.F]=true; Q.push({{w.F,I.F},2});}
                    }
                    else{
                        if(!D[w.F][I.F]){D[w.F][I.F]=true; Q.push({{w.F,I.F},3});}
                    }
                }
                for(auto &I:E4[w.F]){
                    if(!F[I][w.S]){F[I][w.S]=true; Q.push({{I,w.S},4});}
                }
            }
            else if(W.S==1){
                for(auto &I:E1[w.F]){
                    if(!A[I][w.S]){A[I][w.S]=true; Q.push({{I,w.S},0});}
                }
            }
            else if(W.S==2){
                for(auto &I:E2[w.F]){
                    if(!A[I][w.S]){A[I][w.S]=true; Q.push({{I,w.S},0});}
                }
            }
            else if(W.S==3){
                for(int i=0;i<n;i++){
                    if(A[w.S][i] && !A[w.F][i]){A[w.F][i]=true; Q.push({{w.F,i},0});}
                }
            }
            else{
                for(int i=0;i<n;i++){
                    if(A[i][w.F] && !A[i][w.S]){A[i][w.S]=true; Q.push({{i,w.S},0});}
                }
            }
        }
        cout<<(A[s][t]?"Yes":"No")<<endl;
    }
    
    return 0;
}

