#include<bits/stdc++.h> 
using namespace std; 
long long n,f[49],x=1;
int main()
{
    cin>>n;
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=(f[i-1]+f[i-2]);
    
    cout<<f[n]<<endl;
}
