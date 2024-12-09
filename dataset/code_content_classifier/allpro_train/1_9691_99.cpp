#include<bits/stdc++.h>
using namespace std;
map<char,char> mem;
int main(){
  char c;
  int n,m;
  while(cin>>n,n){
    mem.clear();
    for(int i=0;i<n;i++){
      char a,b;
      cin>>a>>b;
      mem[a]=b;
    }
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>c;
      if(mem.find(c)!=mem.end()){
	cout<<mem[c];
      }
      else{
	cout<<c;
      }
    }
    cout<<endl;
  }
}