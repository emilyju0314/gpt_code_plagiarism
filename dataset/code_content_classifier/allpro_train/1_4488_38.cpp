#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PA;
int main(){
  bool sosu[10001];
  PA p,sou[10001];
  for(int i=3;i<=10000;i+=2){
    for(int j=i*i;j<=10000&&sosu[i]==false;j+=i)
      sosu[j] = true;
    if(sosu[i-2] == false && sosu[i] == false)
      p = PA(i-2,i);
    sou[i] = p;
  }
  int a;
  while(cin>>a,a!=0){
    if(a%2 == 0) a--;
    cout << sou[a].first << ' ' << sou[a].second << endl;
  }  
  return (0);
}