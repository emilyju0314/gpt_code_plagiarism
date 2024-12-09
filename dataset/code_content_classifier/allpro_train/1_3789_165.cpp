#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){

 long long int n,m,l,a[200010],b[200010],c[100010];
  
  cin >> n >> m ;
  
  for(int i=0;i<n;i++)
    cin >> a[i];
  for(int i=0;i<n;i++)
    cin >> b[i];
  
  sort(a,a+n);
  sort(b,b+n,greater<long long int>());
  long long int ok=-1,ng=1e13;
  while(ok+1<ng){
    long long int mid=(ok+ng)/2;
    long long int ans=0;
    for(int i=0;i<n;i++){
      if(a[i]*b[i]>mid){
        ans+=a[i]-mid/b[i];
      }
    }
    if(ans<=m){
      ng=mid;
    }
    else{
      ok=mid;
    }
  }
  cout << ng << endl;
}
  
  