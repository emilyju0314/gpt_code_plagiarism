#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    long long a[100000],b[100000];
    long long sum=0,s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int k=0;k<m;k++){
        cin>>b[k];
        s+=b[k];
    }
    cout<<sum*s<<endl;
}

