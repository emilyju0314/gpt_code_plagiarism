#include<iostream>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
long long K,ans=0LL;
int main(){
    cin>>K;
    for(int a=1;a<=K;a++)for(int b=1;b<=K;b++)for(int c=1;c<=K;c++)ans+=gcd(a,gcd(b,c));
    cout<<ans<<endl;
    return 0;
}