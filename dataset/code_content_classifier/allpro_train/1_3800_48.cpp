//01
#include<iostream>
#include<numeric>

using namespace std;

int main(){
  int N;
  cin>>N;
  int a[200][3];
  for(int i=0;i<N;i++){
    cin>>a[i][0]>>a[i][1]>>a[i][2];
  }
  for(int i=0;i<N;i++){
    int s=0;
    for(int j=0;j<3;j++){
      int k;
      for(k=0;k<N;k++){
	if(i==k)continue;
	if(a[i][j]==a[k][j])break;
      }
      if(k==N){
	s+=a[i][j];
      }
    }
    cout<<s<<endl;
  }
  return 0;
}