#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(C) (C).begin(),(C).end()
#define fi first
#define se second

typedef pair<int,string> pis;

const int    val[]={  64,  32,  16,  8,     4,    2,    1};
const string str[]={"R1","R2","R4","R8","R16","R32","R64"};

class st{
public:
  int sc;
  string s;
  bool operator<(const st & a)const{
    if (s.size() != a.s.size())return s.size() < a.s.size();
    return s < a.s;
  }
};

vector<st> all;
void make(){
  rep(i,7){
    int now =val[i];
    string snow=str[i];
    all.pb((st){now,snow});
    REP(j,i+1,7){
      now+=val[j];
      snow+=".";
      all.pb((st){now,snow});
    }
  }
  sort(ALL(all));
  //rep(i,all.size())printf("%4d %s\n",all[i].sc,all[i].s.c_str());
}

const int N = 6400010;
int dp[N];
int path[N];

int encode(string &in){
  int sum=0;
  int p=0;
  while(p < in.size()){
    p++;//in[p]='R';
    int now=0;
    while(p < in.size() && isdigit(in[p]))now=now*10+(in[p++]-'0');
    now = 64/now;
    sum+=now;
    while(p < in.size() && in[p] == '.')p++,sum+=now/2,now/=2;
  }
  return sum;
}

bool cmpstr(string &a,string &b){
  int len=min(a.size(),b.size());
  rep(i,len){
    if (a[i] != b[i])return a[i] < b[i];
  }
  return a.size() > b.size();
}

void solve(int tar){
  rep(i,tar+1)dp[i]=N*10,path[i]=-1;
  dp[0]=0;
  rep(i,tar+1){
    rep(j,all.size()){
      if (i-all[j].sc >= 0 && 
	  (all[j].s.size()+dp[i-all[j].sc] < dp[i] ||
	   (all[j].s.size()+dp[i-all[j].sc]==dp[i]&& 
	    cmpstr(all[j].s,all[path[i]].s)))){
	dp[i]=all[j].s.size()+dp[i-all[j].sc];
	path[i]=j;
      }
    }
  }
  while(path[tar] != -1){
    cout << all[path[tar]].s;
    tar=tar-all[path[tar]].sc;
  }
  cout << endl;
}

int main(){
  make();
  int te;
  cin>>te;
  while(te--){
    string in;
    cin>>in;
    solve(encode(in));
  }
  return false;
}