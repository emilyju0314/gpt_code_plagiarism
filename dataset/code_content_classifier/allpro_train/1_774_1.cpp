#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int H,W;
int t[250000];
int u[250001];
bool rh[250001];
bool rw[250001];

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

bool solve(){
  int sy=t[0]/W;
  int sx=t[0]%W;
  for(int i=1;i<H*W;i++){
    int y=t[i]/W;
    int x=t[i]%W;
    if( abs(y-sy)%2 == 1 )rh[ t[i] ]=true;
    if( abs(x-sx)%2 == 1 )rw[ t[i] ]=true;
  }
  
  int last=-1;
  stack<int> total;
  stack<int> st[4];
  
  for(int i=0;i<H*W;i++){
    int n=t[i];
    vector<P> v;
    for(int dir=0;dir<4;dir++){
      int y=n/W+dy[dir];
      int x=n%W+dx[dir];
      if(y<0||H<=y)continue;
      if(x<0||W<=x)continue;
      int m=y*W+x;
      v.push_back(P(u[m],dir));
    }
    
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    
    for(int j=0;j<(int)v.size();j++){
      int dir=v[j].second;
      int y=n/W+dy[dir];
      int x=n%W+dx[dir];
      int m=y*W+x;
      int ndir=dir;
      if(rh[n]&&ndir%2==0)ndir=(ndir+2)%4;
      if(rw[n]&&ndir%2==1)ndir=(ndir+2)%4;
      stack<int> &w=st[ndir];
      if(u[m]<i){
        //        cout<<"pop  "<<n<<' '<<m<<' '<<ndir<<endl;
        if(w.empty()||w.top()!=n)return false;
        w.pop();
        //        if(total.top()<last)return false;
        total.pop();
        last=i;
      }
    }
    
    for(int j=0;j<(int)v.size();j++){
      int dir=v[j].second;
      int y=n/W+dy[dir];
      int x=n%W+dx[dir];
      int m=y*W+x;
      int ndir=dir;
      if(rh[n]&&ndir%2==0)ndir=(ndir+2)%4;
      if(rw[n]&&ndir%2==1)ndir=(ndir+2)%4;
      stack<int> &w=st[ndir];
      if(u[m]>=i){
        //        cout<<"push "<<n<<' '<<m<<' '<<ndir<<endl;
        w.push(m);
        total.push(i);
      }
    }
  }
  return true;
}

int main(){
  cin>>H>>W;
  for(int i=0;i<H*W;i++){
    cin>>t[i];
    u[t[i]]=i;
  }
  cout<<(solve()?"YES":"NO")<<endl;
  return 0;
}