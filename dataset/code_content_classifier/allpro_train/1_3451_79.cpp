#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int t,n;
  string str;
  bool book[2][50000];
  int v[3][20000],a[3][20000];

  cin >> t;
  while(t--){
    cin >> n >> str;
    for(int i=0;i<2;i++){
      for(int j=0;j<2*n;j++)book[i][j+1] = (str[i*2*n+j]=='Y');
      book[i][0] = book[i][2*n+1] = false;
    }

    for(int i=0;i<3;i++)
      for(int j=0;j<=n;j++){
	v[i][j] = a[i][j] = 100000000;
      }
    a[0][0] = 0;

    for(int i=0;i<=n;i++){
      if(book[1][2*i] || book[1][2*i+1]){
	v[0][i] = min(min(v[0][i],a[0][i] + 3),min(a[1][i] + 2,a[2][i] + 2));
	if(book[0][2*i] || book[0][2*i+1]){
	  v[1][i] = min(min(v[1][i],a[0][i] + 2),min(a[1][i] + 2,a[2][i] + 2));
	  v[2][i] = min(min(v[2][i],a[0][i] + 2),min(a[1][i] + 2,a[2][i] + 3));
	}else{
	  v[1][i] = min(min(v[1][i],a[0][i] + 2),min(a[1][i] + 1,a[2][i] + 1));
	  v[2][i] = min(min(v[2][i],a[0][i] + 2),min(a[1][i] + 1,a[2][i] + 1));
	}
      }else if(book[0][2*i] || book[0][2*i+1]){
	v[0][i] = min(min(v[0][i],a[0][i] + 1),min(a[1][i] + 1,a[2][i] + 2));
	v[1][i] = min(min(v[1][i],a[0][i] + 1),min(a[1][i] + 1,a[2][i] + 2));
	v[2][i] = min(min(v[2][i],a[0][i] + 2),min(a[1][i] + 2,a[2][i] + 3));
      }else{
	v[0][i] = min(min(v[0][i],a[0][i]),min(a[1][i] + 1,a[2][i] + 2));
	v[1][i] = min(min(v[1][i],a[0][i] + 1),min(a[1][i],a[2][i] + 1));
	v[2][i] = min(min(v[2][i],a[0][i] + 2),min(a[1][i] + 1,a[2][i]));
      }

      if(i==n)break;

      for(int j=0;j<3;j++)a[j][i+1] = v[j][i] + 1;
    }
    cout << v[0][n] << endl;
  }  
}