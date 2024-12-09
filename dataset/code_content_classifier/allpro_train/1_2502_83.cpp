#include<bits/stdc++.h>
#define N 10000
using namespace std;

int main(){
  int n,cnt[N];
  set<int> s;
  while(1){
    cin>>n;
    if(!n)break;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<n;i++)s.insert((i*i)%n);
    set<int>::iterator ite,ite2;
    for(ite=s.begin();ite!=s.end();ite++){
      for(ite2=s.begin();ite2!=s.end();ite2++){
	int a=*ite,b=*ite2;
	if(a==b)continue;
	int cal=a-b;
	if(cal<0)cal+=n;
	if(cal>(n-1)/2)cal=n-cal;
	cnt[cal]++;
      }
    }
    for(int i=1;i<=(n-1)/2;i++)cout<<cnt[i]<<endl;
    s.clear();
  }
  return 0;
}