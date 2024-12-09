#include<iostream>
using namespace std;
int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
      for(int j=0;j<n-i;j++){
        if(s[i+j]!=t[j])break;
        if(j==n-i-1){cout<<n+i<<endl;return 0;}
      }
    }
    cout<<n*2<<endl;
    return 0;
}