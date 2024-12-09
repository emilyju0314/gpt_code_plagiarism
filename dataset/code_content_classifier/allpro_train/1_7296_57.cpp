#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,x;cin>>n>>m>>x;
        int a[n];
        cout<<"YES"<<endl;
        set<pair<int,int>> st;
        for(int i=1 ; i<=m ; i++){
            st.insert({0,i});
        }
        for(int i=1 ; i<=n ; i++){
            cin>>a[i];
            pair<int,int> p=*st.begin();
            cout<<p.second<<" ";
            st.erase(p);
            st.insert({p.first+a[i],p.second});
        }
        cout<<endl;
    }
}