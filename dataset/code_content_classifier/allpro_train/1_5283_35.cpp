#include<bits/stdc++.h>
using namespace std;
int n,i,c,x,y;
set<int>S;
int main()
{
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>c>>x;
    if(c==1)cout<<(S.find(x)!=S.end())<<endl;
    else if(c==0)S.insert(x),cout<<S.size()<<endl;
    else if(c==2)S.erase(x);
    else
    {
      cin>>y;
      auto a=S.lower_bound(x),b=S.upper_bound(y);
      for(auto it=a;it!=b;it++)cout<<*it<<endl;
    }
  }
}
