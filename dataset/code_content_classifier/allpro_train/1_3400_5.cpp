#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,n,j,k,e,o;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n][n];
        k=n*n;
        e=2;
        o=1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(o<=k){
                    a[i][j]=o;
                    o+=2;
                }
                else{
                    a[i][j]=e;
                    e+=2;
                }
            }
        }
        if(n==1)cout<<1<<endl;
        else if(n==2)cout<<-1<<endl;
        else{
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
                }cout<<endl;
            }
        }
    }
    return 0;
}
