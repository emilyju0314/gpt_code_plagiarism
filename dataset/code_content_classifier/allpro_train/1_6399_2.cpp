#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF=1000000000;

int N;
string words[101];
int vals[101];
string obj;
int mem[201];
int dp[5001];

int main(){
  int cs=0;
  while(cin>>N&&N){
    for(int i=0;i<N;i++)cin>>words[i]>>vals[i];
    cin>>obj;
    for(int j=obj.size();j>=0;j--){
      int res=0;
      if(j==obj.size())res=0;
      else{
	for(int k=0;k<N;k++){
	  if(j+words[k].size()<=obj.size()
	     &&obj.compare(j,words[k].size(),words[k])
	     ==0){
	    res=max(res,mem[j+words[k].size()]+vals[k]);
	  }
	}
      }
      mem[j]=res;
    }
    int maxLen=mem[0];
    for(int i=0;i<=maxLen;i++){
      int res=INF;
      if(i==0)res=0;
      else{
	for(int j=0;j<N;j++){
	  if(i-vals[j]>=0){
	    res=min(res,dp[i-vals[j]]
		    +(int)words[j].size());
	  }
	}
      }
      dp[i]=res;
    }
    cout<<"Case "<<cs+1<<": "<<dp[maxLen]<<endl;
    cs++;
  }

  return 0;
}