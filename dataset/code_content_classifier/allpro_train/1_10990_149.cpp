#include <bits/stdc++.h>
     
using namespace std;

#define MAX 100000000

int main(){
  int n;
  while(cin >> n,n){
    int tmp=n;
    vector<pair<int,int> > pfact;
    for(int i=2;i*i<=tmp;++i){
      if(tmp%i==0){
	int cnt=0;
	while(tmp%i==0) cnt++,tmp/=i;
	pfact.push_back(make_pair(i,cnt));
      }
    }
    long long sum=1;
    for(int i=0;i<pfact.size();++i){
      int s;
      int a=pfact[i].first,b=pfact[i].second;
      if(tmp==i) s=((long long)pow(a,b+2)-1)/(a-1),tmp=0;
      else s=((long long)pow(a,b+1)-1)/(a-1);
      sum*=s;
    }
    if(tmp>1) sum*=(tmp+1);
    if(n==1) sum=0;
    sum-=n;
    
    if(sum==n) cout << "perfect number" << endl;
    else if(sum<n) cout << "deficient number" << endl;
    else cout << "abundant number" << endl;
  }
  
  return 0;
}

