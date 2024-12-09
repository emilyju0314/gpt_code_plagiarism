#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        
        int cnt=0;
        for(int i=n;i>=1;i--){
            if(a[i]!=i){
                cnt=i;
                break;
            }
        }
        double res=1;
        for(int i=1;i<=m;i++){
            pair<int,double>temp;
            cin>>temp.first>>temp.second;
            if(temp.first>=cnt)res*=(1-temp.second);
        }
        if(cnt==0)cout<<"1.000000000"<<endl;
        else printf("%.9lf\n",1-res);
    }
}
