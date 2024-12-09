#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
void fn(vector<int>& a,char s){
  if(0){
  }else if(s=='n'){
    int s=a[0];
    a[0]=a[4];
    a[4]=a[5];
    a[5]=a[1];
    a[1]=s;
  }else if(s=='s'){
    int s=a[0];
    a[0]=a[1];
    a[1]=a[5];
    a[5]=a[4];
    a[4]=s;
  }else if(s=='e'){
    int s=a[0];
    a[0]=a[2];
    a[2]=a[5];
    a[5]=a[3];
    a[3]=s;
  }else if(s=='w'){
    int s=a[0];
    a[0]=a[3];
    a[3]=a[5];
    a[5]=a[2];
    a[2]=s;
  }
  return;
}
int main(){
  int i,j;
  int h,w;
  while(cin>>h>>w,h||w){
    int a[12][12];
    memset(a,-1,sizeof(a));
    for(i=1;i<h+1;i++)
      for(j=1;j<w+1;j++)
	cin>>a[j][i];
    int sx,sy,tx,ty;
    cin>>sy>>sx>>ty>>tx;
    sx++;
    sy++;
    tx++;
    ty++;
    int b[12][12][7][7];
    memset(b,-1,sizeof(b));
    priority_queue<pair<pair<int,vector<int> >,pair<int,int> >,vector<pair<pair<int,vector<int> >,pair<int,int> > >,greater<pair<pair<int,vector<int> >,pair<int,int> > > > c;
    vector<int> d;
    for(i=1;i<7;i++)
      d.push_back(i);
    c.push(make_pair(make_pair(0,d),make_pair(sx,sy)));
    while(c.empty()==0){
      int x,y,z;
      vector<int> d;
      x=c.top().second.first;
      y=c.top().second.second;
      z=c.top().first.first;
      d=c.top().first.second;
      if(x==tx&&y==ty)
	break;
      c.pop();
      if(b[x][y][d[0]][d[1]]==-1||b[x][y][d[0]][d[1]]>z){
	b[x][y][d[0]][d[1]]=z;
	if(a[x-1][y]!=-1){
	  fn(d,'e');
	  c.push(make_pair(make_pair(z+a[x-1][y]*d[5],d),make_pair(x-1,y)));
	  fn(d,'w');
	}
	if(a[x+1][y]!=-1){
	  fn(d,'w');
	  c.push(make_pair(make_pair(z+a[x+1][y]*d[5],d),make_pair(x+1,y)));
	  fn(d,'e');
	}
	if(a[x][y-1]!=-1){
	  fn(d,'s');
	  c.push(make_pair(make_pair(z+a[x][y-1]*d[5],d),make_pair(x,y-1)));
	  fn(d,'n');
	}
	if(a[x][y+1]!=-1){
	  fn(d,'n');
	  c.push(make_pair(make_pair(z+a[x][y+1]*d[5],d),make_pair(x,y+1)));
	  fn(d,'s');
	}
      }
    }
    cout<<c.top().first.first<<endl;
  }
  return 0;
}