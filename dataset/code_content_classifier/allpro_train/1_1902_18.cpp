#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  int n;
  char ss[1010];
  char ans[1010];
  int d;
  scanf("%d",&n);
  scanf("%s",ss);
  scanf("%d",&d);
  strcpy(ans,ss);
  for(int i=0;(i<n) && d;i++){
    if(ans[i] == '0'){
      ans[i]='1';
      d--;
    }
  }
  for(int i=n-1;(i>=0) && d;i--){
    if(ans[i] == '1' && ss[i]=='1'){
      ans[i]='0';
      d--;
    }
  }
  printf("%s\n",ans);
  return 0;
}