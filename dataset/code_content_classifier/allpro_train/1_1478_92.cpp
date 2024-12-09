#include<bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,vector<T> const& v){for(auto itr=v.begin();itr!=v.end();++itr){if(itr!=v.begin())os<<' ';os<<*itr;}return os;}

struct point{
  int64_t x,y;
  point(){}
  point(double _x,double _y):x(_x),y(_y){}

  bool operator < (point const& rhs)const{
    return this->x==rhs.x?this->y<rhs.y:this->x<rhs.x;
  }

  friend istream& operator>>(istream& is,point& p){
    return is>>p.x>>p.y;
  }
  friend ostream& operator<<(ostream& os,point const& p){
    return os<<p.x<<" "<<p.y;
  }
};

signed main(){

  int n;
  cin>>n;
  vector<point> a(n);
  for(auto& ai:a)cin>>ai;
  sort(a.begin(),a.end());
  for(auto ai:a){
    cout<<ai<<endl;
  }

}
