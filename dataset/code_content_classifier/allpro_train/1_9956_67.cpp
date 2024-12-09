#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;

typedef vector<vector<int> > Mat;

long long W,H,N;

Mat operator*(const Mat &a,const Mat &b){
  Mat m(W,vector<int>(W));
  for(int i=0;i<W;i++){
    for(int j=0;j<W;j++){
      for(int k=0;k<W;k++){
	m[i][j]=(m[i][j]+a[i][k]*1LL*b[k][j])%1000000009;
      }
    }
  }
  return m;
}

Mat bm(const set<int> &s=set<int>()){
  Mat m(W,vector<int>(W));
  for(int i=0;i<W;i++){
    if(s.count(i)==0){
      for(int j=-1;j<=1;j++){
	int x=i+j;
	if(0<=x&&x<W){
	  m[i][x]=1;
	}
      }
    }
  }
  return m;
}

Mat pm(const Mat &m,long long p){
  if(p==0){
    Mat m(W,vector<int>(W));
    for(int i=0;i<W;i++){
      m[i][i]=1;
    }
    return m;
  }else{
    auto r=pm(m*m,p>>1);
    if(p%2){
      r=r*m;
    }
    return r;
  }
}

int main(){
  for(int t=1;cin>>W>>H>>N,W;t++){
    map<long long,set<int> > m;
    while(N--){
      long long x,y;
      cin>>x>>y;
      if(y>1){
	m[y-1].insert(x-1);
      }
    }
    vector<Mat> v;
    long long l=0;
    for(auto e:m){
      v.push_back(pm(bm(),e.first-l-1));
      v.push_back(bm(e.second));
      l=e.first;
    }
    v.push_back(pm(bm(),H-l-1));
    auto am=pm(bm(),0);
    for(int i=v.size()-1;i>=0;i--){
      am=am*v[i];
    }
    cout<<"Case "<<t<<": "<<am[W-1][0]<<endl;
  }
}