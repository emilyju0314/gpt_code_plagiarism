#include<iostream>
using namespace std;

int main(){
  while(1){

  int n,m;
  int mn[1001],cnt[101]={},ans[1001]={},ansm=0;
  string str[101],str2[1001];
  cin>>n>>m;
  if(n+m==0) break;
  for(int i=0;i<n;i++)cin>>str[i]>>mn[i];

  for(int i=0;i<n;i++)
    for(int j=0;j<8;j++)if(str[i][j]>='0' && str[i][j]<='9') cnt[i]++;

  for(int i=0;i<m;i++) cin>>str2[i];

  for(int i=0;i<n;i++){
      for(int k=0;k<m;k++){
	ans[k]=0;
	for(int j=7;j>=0;j--)if(str2[k][j]==str[i][j])ans[k]++;
	if(ans[k]==cnt[i])  ansm+=mn[i];
	}
  }

        cout<<ansm<<endl;
  }
    return 0;

}