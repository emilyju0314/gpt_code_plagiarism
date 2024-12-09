#include <bits/stdc++.h> 
using namespace std; 
void solve() 
{ 
  int n;
  cin>>n;
   vector<int>a;
   int f;
   int o=0;
    for(int i=0;i<n;i++)
    {
        cin>>f;
        if(f>0)
        o=1;
        a.push_back(f);
    }
  sort(a.begin(),a.end());
  int cnt=0;
  int i=0;
  int d=INT_MAX;
  while(i<n&&a[i]<=0)
  {
  	 cnt++;
  	 i++;
  }
      if(o==0)
      {
      	cout<<cnt<<endl;
      	return;
	  }
  int l=1;
    while(l<n&&a[l]<=0)
    {
        d=min(abs(a[l]-a[l-1]),d);
        l++;
    }
    
    if(a[l]<=d)cnt++;
    cout<<cnt<<endl;
}
int main() 
{ 
//  ios::sync_with_stdio(0); 
//  cin.tie(0); 
  int t;
  cin >>t;
  while(t--)
  {
    solve();
  }
  return 0; 
} 