#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,q; cin>>n>>k>>q;
  vector<int> a(q); for(int i=0;i<q;i++) cin>>a[i],a[i]--;
  vector<int> b(n,0);
  for(int i=0;i<q;i++) b[a[i]]++;
  for(int i=0;i<n;i++) cout<<(k-q+b[i]>0?"Yes":"No")<<endl;
}