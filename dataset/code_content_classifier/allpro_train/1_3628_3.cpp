#include<iostream>
#include<numeric>
#include<map>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)



#define rotate_swap(x,a,b,c,d) swap(x.a,x.b);swap(x.b,x.c);swap(x.c,x.d);

class Dice{
public:
  int top,front,right,left,back,bottom;
};

void rotate_r(Dice &x){
  rotate_swap(x,top,left,bottom,right);
}

void rotate_f(Dice &x){
  rotate_swap(x,top,back,bottom,front);
}

void rotate_cw(Dice &x){
  rotate_swap(x,back,left,front,right);
}


Dice data[4][24];
void generate_all(Dice *x,int n){
  rep(k,n){
    rep(i,6){
      rep(j,4){
	data[k][i*4+j]=x[k];
	rotate_cw(x[k]);
      }
      if (i%2 == 0)rotate_r(x[k]);
      else rotate_f(x[k]);
    }
  }
}


int ans;

void count_min(int n,Dice *in){
  int color[6];
  rep(i,6)color[i]=(1<<20);
  rep(i,n){
    int tcolor[6]={0};
    rep(j,n){
      if (in[i].front  != in[j].front)tcolor[0]++;
      if (in[i].right  != in[j].right)tcolor[1]++;
      if (in[i].left   != in[j].left) tcolor[2]++;
      if (in[i].bottom != in[j].bottom)tcolor[3]++;
      if (in[i].top    != in[j].top)   tcolor[4]++;
      if (in[i].back   != in[j].back)tcolor[5]++;
    }
    rep(j,6)color[j]=min(color[j],tcolor[j]);
  }
  ans=min(ans,accumulate(color,color+6,0));
}

void search(int n,int now,Dice *in){
  if (n == now){
    count_min(n,in);
    return;
  }
  rep(i,24){
    in[now]=data[now][i];
    search(n,now+1,in);
  }
}

int solve(Dice *in,int n){
  ans=(1<<21);
  generate_all(in,n);
  search(n,0,in);
  return ans;
}

int getname(string &in,map<string,int> & M){
  int index=M.size();
  if (M.find(in) == M.end())M[in]=index;
  return M[in];
}

int main(){
  int n;
  Dice in[4];
  while(cin>>n && n){
    map<string,int> M;
    rep(i,n){
      string tmp;
      cin>>tmp;
      in[i].front=getname(tmp,M);
      cin>>tmp;
      in[i].right=getname(tmp,M);
      cin>>tmp;
      in[i].top=getname(tmp,M);
      cin>>tmp;
      in[i].bottom=getname(tmp,M);
      cin>>tmp;
      in[i].left=getname(tmp,M);
      cin>>tmp;
      in[i].back=getname(tmp,M);
    }
    cout << solve(in,n) << endl;
  }
}