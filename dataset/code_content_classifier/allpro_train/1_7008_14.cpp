#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef long long ll;
typedef pair<ll,ll> PP;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

signed main(void){
    
    string S;
    cin >> S;
    int a[26]={};
    REP(i,S.size()){
        a[S[i]-'a']++;
    }
    int kisu=0;
    int Ans=0;
    REP(i,26){
        if(a[i]%2==1)kisu++;
    }
    
    Ans = kisu/2;
    
    cout << Ans << endl;
    
    return 0;
}



