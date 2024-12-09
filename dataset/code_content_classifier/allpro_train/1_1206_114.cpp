#include<iostream>
#include<map>
using namespace std;
#define START 0
#define END 1

int main()
{
  while(true){
    int n;
    scanf("%d", &n);
    if(n==0)break;
    multimap<int,pair<int,int> > M; 
    for(int i = 0; i < n; ++i){
      int m,a,b;
      scanf("%d%d%d", &m, &a, &b);
      M.insert(make_pair(a,make_pair(START,m)));
      M.insert(make_pair(b,make_pair(END,m)));
    }
    
    int total = 0;
    bool ng=false;
    for(map<int,pair<int,int> >::iterator itm = M.begin();
	itm != M.end();
	++itm)
      {
	int t=itm->first;
	while(t==itm->first){
	  if(itm->second.first==START){
	    total += itm->second.second;
	  }else{
	    total -= itm->second.second;
	  }
	  ++itm;
	  if(itm==M.end())break;
	}
	if( total > 150 ){
	  ng = true;
	}
	--itm;
      }

    if( ng ){
      puts("NG");
    }else{
      puts("OK");
    }
  }
  return 0;
}