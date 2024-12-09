#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int n, i, f=1; cin>>n;
        string s; cin>>s;
        int t=0, m=0;
        for(i=0; i<n; i++){
            if(s[i]=='T') t++;
            else m++;
            if(m>t) f=0;
        }
        if(2*m!=t) f=0;
        t=0, m=0;
        for(i=n-1; i>=0; i--){
           if(s[i]=='T') t++;
            else m++;
            if(m>t) f=0;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
