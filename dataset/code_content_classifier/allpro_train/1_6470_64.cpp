#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N=1e9;
int main(){
    ll s;cin>>s;
    ll x3=(s%N==0 ? 0:N-s%N);
    ll y3=(s+x3)/N;
    cout<<"0 0 1000000000 1 "<<x3<< " " <<y3<<endl;
}