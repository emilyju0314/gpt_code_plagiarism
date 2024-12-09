#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> str;
string mem[15][15];
typedef pair <string,int> P;

string con(string a,string b){
  int K=0;
  for(int i=0;i<a.size();i++){
    int j=i,k=0;
    while(a[j]&&b[k]&&a[j]==b[k]) j++,k++;
    if(!a[j]||!b[k])K=max(K,k);
  }
  return b.substr(K,b.size());
}

string solve(){
  string dp[1<<14][14];
  for(int i=0;i<n;i++) dp[1<<i][i]=str[i];
  
  for(int i=0;i<(1<<n);i++)
    for(int k=0;k<n;k++){
      if(dp[i][k]=="")continue;
      for(int j=0;j<n;j++){
	if((i&(1<<j)))continue;
	string nx=dp[i][k]+mem[k][j];
	int ni=i|1<<j;
	if(!dp[ni][j].size()||nx.size()<dp[ni][j].size()) dp[ni][j]=nx;
	else if(nx.size()==dp[ni][j].size()&&dp[ni][j]>nx)dp[ni][j]=nx;
      }
    }

  string res;
  for(int i=0;i<n;i++) {
    if(dp[(1<<n)-1][i]=="")continue;
    if(res==""||res.size()>dp[(1<<n)-1][i].size()) res=dp[(1<<n)-1][i];
    else if(dp[(1<<n)-1][i].size()==res.size()) res=min(res,dp[(1<<n)-1][i]);
  }
  return res;
}

int main(){
  
  while(cin>>n,n){
    str.resize(n);
    for(int i=0;i<n;i++)cin>>str[i];

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
	if(i==j)continue;
	if(con(str[i],str[j])==""){
	  str.erase(str.begin()+j);
	  n--;
	  i=-1;
	  break;
	}
      }
    
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)mem[i][j]=con(str[i],str[j]);

    cout<<solve().size()<<endl;
  }

  return 0;
}