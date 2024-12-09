#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
  int field[14][14];
  int xx[12]={1,2,3,0,0,0,-1,-2,-3,0,0,0};
  int yy[12]={0,0,0,1,2,3,0,0,0,-1,-2,-3};
  string line;
  queue<int> search;
  int x,y;
  int n,k;
  cin>>n;
  for(k=0;k<n;k++){
    for(y=0;y<14;y++){
      for(x=0;x<14;x++){
	field[x][y] = 0;
      }
    }
    for(y=0;y<8;y++){
      cin>>line;
      for(x=0;x<8;x++){
	if (line[x]=='1')
	  field[x+3][y+3] = 1;
      }
    }
    cin>>x>>y;
    x+=2;
    y+=2;
    field[x][y]=0;
    search.push(y*14+x);
    while(!(search.empty())){
      for(int i=0;i<12;i++){
	if(field[search.front()%14+xx[i]][search.front()/14+yy[i]]){
	  field[search.front()%14+xx[i]][search.front()/14+yy[i]]=0;
	  search.push(search.front()+yy[i]*14+xx[i]);
	}
      }
      search.pop();
    }
    cout<<"Data "<<k+1<<":"<<endl;
    for(int y=3;y<11;y++){
      for(int x=3;x<11;x++){
	cout<<field[x][y];
      }
      cout<<endl;
    }
  }
  return 0;
}