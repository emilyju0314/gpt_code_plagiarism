#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

class chara{
public:
  string name;
  int vote;
  bool operator<(const chara &x)const{
    return (vote==x.vote)?(name<x.name):(vote>x.vote);
  }
};

int main(){
  int n,m,k,l;
  chara c[100000];

  while(scanf("%d %d %d %d",&n,&m,&k,&l) &&(n||m||k||l)){
    char tmp[12];
    int x;
    for(int i=0;i<n;i++){
      scanf("%s %d",tmp,&x);
      c[i].name = tmp;
      c[i].vote = x;
    }

    sort(c,c+n);

    map<string,bool> fav;
    for(int i=0;i<m;i++){
      scanf("%s",tmp);
      string s = tmp;
      fav[s] = true;
    }

    int ans = 0;
    int pos = k-1;
    int now = k;
    for(;;){
      while(0<=pos && fav[c[pos].name])pos--;
      if(pos<0)break;

      while(now<n && !fav[c[now].name])now++;
      if(now==n)break;

      swap(c[now],c[k]);
      for(int i=pos;i<k;i++){
	l -= c[i].vote-c[i+1].vote;
	c[i+1].vote = c[i].vote;
	if(c[i].name<c[i+1].name){
	  l--;c[i+1].vote++;
	}
	if(l<0)break;
	swap(c[i],c[i+1]);
      }
      if(l<0)break;
    }

    for(int i=0;i<k;i++)if(fav[c[i].name])ans++;
     
    printf("%d\n",ans);
  }
}