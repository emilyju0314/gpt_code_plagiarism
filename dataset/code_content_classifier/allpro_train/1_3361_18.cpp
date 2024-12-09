//Magical Tiles
#include<bits/stdc++.h>
using namespace std;

vector<string> mp;
int a[100][100];

bool solve(int y, int x){
  if(a[y][x]==1)return false;//すでに通った
  a[y][x]=1;

  if(mp[y][x]=='.'){cout<<x<<' '<<y<<endl; return true;}
  else if(mp[y][x]=='>')x++;
  else if(mp[y][x]=='v')y++;
  else if(mp[y][x]=='<')x--;
  else if(mp[y][x]=='^')y--;

  if(solve(y, x))return true;
  else return false;
}

int main(){
  int h, w;
  while(true){
    cin>>h>>w;
    if(h==0 && w==0)break;
    mp.clear();
    memset(a, 0, sizeof(a));
    for(int i=0; i<h; i++){
      string s;
      cin>>s;
      mp.push_back(s);
    }
    if(!solve(0, 0))cout<<"LOOP"<<endl;
  }
  return 0;
}