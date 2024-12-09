#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,W=0,B=0,R=0,X=100000;
  cin >> a >> b;
  char maps[a][b];
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin >> maps[i][j];
    }
  }
  W=0;
  for(int i=0;i<a-2;i++){
    for(int j=0;j<b;j++){
      if(maps[i][j]!='W'){
	W++;
      }
    }
    B=0;
    for(int j=i+1;j<a-1;j++){
      for(int k=0;k<b;k++){
	if(maps[j][k]!='B'){
	  B++;
	}
      }
      R=0;
      for(int k=j+1;k<a;k++){
	for(int l=0;l<b;l++){
	  if(maps[k][l]!='R'){
	    R++;
	  }
	}
      }
      if(X>W+B+R){
	X=W+B+R;
      }
    }
  }
  cout << X << endl;
  return 0;
}