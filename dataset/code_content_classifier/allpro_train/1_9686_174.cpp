#include<iostream>
using namespace std;
long long n,a,b;
int main(){
    cin>>n>>a>>b;
    if(a>b or (n==1 and a!=b))cout<<0<<endl;
    else if(a==b)cout<<1<<endl;
    else cout<<(a-b)*(2-n)+1<<endl;
}