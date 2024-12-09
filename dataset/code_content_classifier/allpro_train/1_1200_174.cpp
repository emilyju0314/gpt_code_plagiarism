#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,m[101],sum=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>m[i];
        sum+=m[i];
    }
    sort(m,m+n);
    cout<<n+((x-sum)/m[0]);
    return 0;
}
