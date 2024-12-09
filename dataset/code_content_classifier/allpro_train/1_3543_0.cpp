#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back
#define ALL(C)    (C).begin(),(C).end()

typedef long long ll;

const int N = 100;
const int M = 10000;
const int dinf=20000;
const ll inf = (1LL)<<50;

class Seat{
public:
  int a,b;
  ll time;
  bool operator<(const Seat & t)const{
    return a < t.a;
  }
};

int ind,amax,amin,al,ar;

void update(int tindex,int l,int r,int posl,int posr){
  if (l > r)swap(l,r);
  
  if (ind==-1||
      (l>amin)||
      (l==amin&&r >amax)){
    //||(l==amin&&r==amax&&tindex < ind)||
    //(l==amin&&r==amax&&tindex==ind&&posl<al)){
    ind=tindex;
    amin=l;
    amax=r;
    al=posl;
    ar=posr;
  }
}

void makeupdate(int tindex,int b,int a,int cap,int req){
  int tmp = a-b-1;
  if (tmp < req)return;
  int val=tmp-req;
  int l,r;
  l=val/2;r=val/2;
//   if (tmp%2 == 1 && req%2 == 0){
//     r++;
//   }else if (tmp%2 == 0 && req%2 == 1){
//     r++;
//   }
  if (val%2 == 1)r++;
  update(tindex,l,r,b+1+l,a-1-r);
}

void check(int cap,vector<Seat> &info,int req,int tindex){
  if (info.size() == 0){
    if (req > cap)return;
    if(req-1<cap)update(tindex,dinf,dinf,0,req-1);
    return;
  }
  
  if (info[0].a >= req){
    update(tindex,dinf,info[0].a-req,0,req-1);
  }  

  rep(i,(int)info.size()-1){
    makeupdate(tindex,info[i].b,info[i+1].a,cap,req);
  }

  if (cap-info[info.size()-1].b-1 >=req){
    update(tindex,cap-req-info[info.size()-1].b-1,dinf,cap-req,cap-1);
  }
}

void getseat(int n,vector<Seat> *a,int *cap,int req){
  rep(i,n){
    if (cap[i]>=req)check(cap[i],a[i],req,i);
  }
}

double solve(int n,int *cap,ll cl,int m,ll *come,int *num,ll *wait,ll *eat){
  ll now=-1;
  int top=0;
  double sum=0,div=0;
  vector<Seat> seat[N];
  rep(i,m)div+=num[i];
  
  while(top < m){
    ll fast=inf;
    rep(i,n){
      rep(j,seat[i].size()){
	fast=min(fast,seat[i][j].time);
      }
    }
    
    if (now < come[top] && come[top] < fast){//arrive
      now=come[top];
    }else if (fast != inf && fast > come[top]+wait[top]){//leave from queue
      now=come[top]+wait[top];
      sum+=(-1)*num[top];
      top++;
    }else now = fast;////leave from seat
    
    //    cout << now <<" " << cl << endl;

    if (now >=cl)break;

    rep(i,n){
      for(int j=(int)seat[i].size()-1;j>=0;j--){
	if (seat[i][j].time <= now){
	  seat[i].erase(seat[i].begin()+j);
	}
      }
    }

//      rep(i,n){
//        rep(j,seat[i].size()){
//   	cout <<"seat info " <<i<<" " <<  seat[i][j].a <<" " << seat[i][j].b <<" " << seat[i][j].time<<endl;
//        }
//      }
       
    while(top < m){
      while(top<m){
	if (now > come[top]+wait[top]){
	  sum+=(-1)*num[top];
	}else break;
	top++;
      }
      
      if (top == m || now < come[top])break;
      
      ind=-1;
      getseat(n,seat,cap,num[top]);
      if (ind == -1)break;
      
      seat[ind].pb((Seat){al,ar,now+eat[top]});
      //      cout << top <<" can sit " << ind <<" " << al <<" " << ar <<" "<<
      //	now <<" " << now+eat[top] <<  endl;
      sort(ALL(seat[ind]));
      sum+=((wait[top]-(now-come[top]))/(double)wait[top])*num[top];
      top++;
    }
  }
  REP(i,top,m)sum+=(-1)*num[i];
  return sum/div;
}

int main(){
  int n,m;
  ll t;
  int cap[N];
  int num[M];
  ll come[M],wait[M],eat[M];
  while(cin>>n>>m>>t && n){
    rep(i,n)cin>>cap[i];
    rep(i,m)cin>>come[i]>>num[i]>>wait[i]>>eat[i];
    printf("%.16lf\n",solve(n,cap,t,m,come,num,wait,eat));
  }
  return false;
}


/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
0 0 0 x x x 4 4 4 7  7  7     2  2  2  8  8  8     3  3  3  9  9  9     1  1  1  
*/