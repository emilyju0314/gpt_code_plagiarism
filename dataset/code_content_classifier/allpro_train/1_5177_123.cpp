#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
    const long long inf=1000000000000000000;
    int n,m;
    cin>>n>>m;
    int a[m],b[m],c[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--,b[i]--;
    }
    vector<long long>dist(n,inf);
    dist[0]=0;
    for(int i=0;i<n*2;i++){
        int update=0;
        for(int j=0;j<m;j++){
            if(b[j]==n-1 && dist[b[j]]>dist[a[j]]-c[j])update=1;
            dist[b[j]]=min(dist[b[j]],dist[a[j]]-c[j]);
        }
        if(i>=n && update){
            cout<<"inf"<<endl;
            return 0;
        }
    }
    cout<<-dist[n-1]<<endl;
    return 0;
}