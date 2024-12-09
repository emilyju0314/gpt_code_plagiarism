#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int n,k=0,A[1000][1000];
    cin>>n;
    rep(i,1000) if(i*(i-1)==2*n) k=i;
    if(!k){cout<<"No";return 0;}
    int z=1;
    rep(i,k){
        rep(j,i) A[i][j]=A[j][i-1];
        for(int j=i;j<k-1;j++) A[i][j]=z,z++;
    }
    cout<<"Yes"<<endl;
    cout<<k<<endl;
    rep(i,k){
        cout<<k-1<<" ";
        rep(j,k-1) cout<<A[i][j]<<" ";
        cout<<endl;
    }
}