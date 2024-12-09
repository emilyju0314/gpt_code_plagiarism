#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
struct P{
  double x,y,z,r;
  P(double x,double y,double z,double r):x(x),y(y),z(z),r(r){}
};

double G[101][101];
double dist(const P& a,const P& b){
  double dx=a.x-b.x;
  double dy=a.y-b.y;
  double dz=a.z-b.z;
  double d = sqrt(dx*dx+dy*dy+dz*dz);
  return max(0.0,d-a.r-b.r);
}
int n;
const double INF = 1000000000;

double prim(){
  double ret = 0;
  double dst[150];
  bool used[150];
  memset(used,0,sizeof(used));
  for(int i=0;i<n;++i) dst[i]=INF;
  dst[0]=0;
  while(true){
    double mindst = INF;
    int id = -1;
    for(int i=0;i<n;++i){
      if(!used[i] && mindst > dst[i]){
	mindst = dst[i];
	id = i;
      }
    }
    if(id==-1) break;
    used[id]=true;
    ret+=mindst;
    for(int i=0;i<n;++i)
      dst[i]=min(dst[i],G[id][i]);
  }
  return ret;
}

int main(){
  while(cin>>n,n){
    memset(G,0,sizeof(G));
    vector<P> cell;
    for(int i=0;i<n;++i){
      double a,b,c,d;
      cin >> a >> b >> c >> d;
      cell.push_back(P(a,b,c,d));
    }
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
	G[i][j]=G[j][i]=dist(cell[i],cell[j]);
    cout << fixed << setprecision(3) << prim() << endl;
  }
  return 0;
}