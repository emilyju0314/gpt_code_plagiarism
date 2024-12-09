#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<#x<<"="<<x<<endl

using P=pair<int,int>;

int main(){
    int n,k;
    cin>>n>>k;
    if(k==2){
        cout<<"Yes"<<endl;
        return 0;
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
        --p[i];
    }
    if(n==k){
        for (int i = 0; i < n-1; ++i) {
            if(p[i]!=n-1&&p[i]>p[i+1]){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }

    vector<bool> vis(n,false);
    int ms=0;
    for (int i = 0; i < n; ++i) {
      if(vis[i])continue;
      int crt=i;
      int d=0;
      while(!vis[crt]){
        vis[crt]=true;
        d++;
        crt=p[crt];
      }
      d%=2;
      if(d==0)ms++;
    }
    ms%=2;

    if(k%2==1&&ms%2==1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}

