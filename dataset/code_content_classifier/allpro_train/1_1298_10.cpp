#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

struct Data {
  int x,dir,index;
};

int n,l,cnt[1000];

void compute(vector<Data> vec){
  int timer = 0, ant = -1;
  while( !vec.empty() ){
    ++timer;
    rep(i,l+1) cnt[i] = 0;
    vector<Data> nvec = vec;
    rep(i,nvec.size()) {
      nvec[i].x += nvec[i].dir;
      ++cnt[nvec[i].x];
    }
    vector<Data> inner,outer;
    rep(i,nvec.size()) {
      if( nvec[i].x == 0 || nvec[i].x == l ) {
	outer.push_back(nvec[i]);
      } else {
	inner.push_back(nvec[i]);
      }
    }
    
    rep(i,l+1) if( cnt[i] >= 2 ){
      rep(j,inner.size()) if( inner[j].x == i ) {
	inner[j].dir *= -1;
      }
    }

    vec = inner;
    if( vec.empty() ) {
      if( outer.size() == 1 ) ant = outer[0].index + 1;
      else {
	assert( outer.size() == 2 );
	rep(i,outer.size()) if( outer[i].x == 0 ) {
	  ant = outer[i].index + 1;
	  break;
	}
      }
    }
  }
  cout << timer << " " << ant << endl;
}

int main(){
  while( cin >> n >> l, n|l ) {
    vector<Data> vec(n);
    rep(i,n){
      char d;
      cin >> d >> vec[i].x;
      vec[i].dir = ((d=='L')?-1:1);
      vec[i].index = i;
    }
    compute(vec);
  }
  return 0;
}