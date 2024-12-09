#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,s=0,a=10;
    cin>>n;
    if(n%2==1){
        cout<<0;
    }
    else{
        while(a<=n){
            s+=n/a;
            a*=5;
        }
        cout<<s;
    }
}
