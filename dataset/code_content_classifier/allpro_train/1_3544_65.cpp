#include<bits/stdc++.h>
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    vector<pair<double,string> > lis;
    lp(i,n){
      string l;
      int p,a,b,c,d,e,f,s,m;
      cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      double ans;
      ans=(double)((f*m*s)-p)/(a+b+c+(d+e)*m);
      lis.push_back(make_pair(-ans,l));
    }
    sort(lis.begin(),lis.end());
    reverse(lis.begin(),lis.end());
    while(!lis.empty()){
      pair<double,string> gege = lis.back();
      cout<<gege.second<<endl;
      lis.pop_back();
    }
    cout<<"#"<<endl;
  }
  return 0;
}
	   

