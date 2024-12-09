//53
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  for(int n,m;cin>>n>>m,n|m;){
    int c[10];
    for(int i=0;i<n;i++){
      cin>>c[i];
    }
    int mm[100001];
    fill(mm,mm+m+1,1<<29);
    mm[0]=0;
    for(int i=0;i<1<<n;i++){
      int cc=0;
      for(int j=0;j<n;j++){
	if(i>>j&1){
	  cc+=c[j];
	}
      }
      for(int j=0;j+cc<=m;j++){
	mm[j+cc]=min(mm[j+cc],mm[j]+1);
      }
    }
    cout<<mm[m]<<endl;
  }
  return 0;
}