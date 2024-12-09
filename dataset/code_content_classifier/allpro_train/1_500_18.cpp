#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <map>

using namespace std;

int main(){
  int n;cin>>n;
  map<int,bool> m[3];
  for(int i=0;i<3;i++){
    int num;cin>>num;
    for(int j=0;j<num;j++){
      int id;cin>>id;
      m[i][id] = true;
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    if((!m[0][i]&&m[2][i]) || (m[1][i]&&m[2][i])){
      cnt++;
    }
  }
  cout<<cnt<<endl;
}
