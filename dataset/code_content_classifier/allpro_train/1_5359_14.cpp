#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    int n; cin>>n;

    if(n==0) break;
    
    vector<double> sx(n),sy(n),sz(n);
    
    for(int i=0; i<n; i++){
      cin>>sx[i]>>sy[i]>>sz[i];
    }
    
    int m; cin>>m;
    
    vector<double> tx(m),ty(m),tz(m),kaku(m);
    
    for(int  i=0; i<m; i++){
      cin>>tx[i]>>ty[i]>>tz[i]>>kaku[i]; 
    }
    
    int count=0;
    
  set<int> s;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s.count(i))continue;
      
      double seki = tx[j]*sx[i] + ty[j]*sy[i]+ tz[j]*sz[i];
      
      double pLong = sqrt(sx[i]*sx[i] + sy[i]*sy[i] + sz[i] * sz[i]);
      
      double kLong = sqrt(tx[j]*tx[j] + ty[j]*ty[j] + tz[j] * tz[j]);

      double theta = acos(seki / (pLong * kLong));
      
      if(theta <=kaku[j]){
        count++;
        s.insert(i);
      }
    }
  }
  cout<<count<<endl;
  }
  
  return 0;
}

