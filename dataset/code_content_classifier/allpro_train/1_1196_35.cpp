#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  int n,a;
  cin >> n;
  string s[n],okita;
  int t[n],sum=0;
  r(i,n){
    cin >> s[i] >> t[i];
  }
  cin>>okita;
 r(i,n)if(s[i]==okita)a=i;
 for(int i=a+1;i<n;i++)sum+=t[i];
  cout<<sum<<endl;
}