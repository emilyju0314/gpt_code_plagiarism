#include<iostream>
using namespace std;

int main(){
  int a[100];
  int ans[100];
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=n-1;i>=0;i--){
    int add=-1;
    for(int j=0;j<=i;j++){
      if(a[j]==j+1){add=j;}}
      if(add==-1){cout<<-1<<endl;return 0;}
      else{
        ans[i]=add+1;
        for(int k=add;k<=i;k++){
          a[k]=a[k+1];
        }
      }

  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
}
