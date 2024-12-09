#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-7)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define pow2(a) ((a)*(a))

using namespace std;

typedef pair<double,double> dd;
const int MAX_N = 110;
const double DINF = 1e20;

int N,T,R;
double t[MAX_N][1100];
int size[MAX_N];
double x[MAX_N][1100],y[MAX_N][1100],tmp_x[MAX_N],tmp_y[MAX_N];
double vx[MAX_N][1100],vy[MAX_N][1100];
string nickname[MAX_N];
bool knows[MAX_N];

bool LT(double a ,double b){ return !equals(a,b) && a < b; }
bool LTE(double a,double b){ return  equals(a,b) || a < b; }

double getDist(double X,double Y){ return sqrt( X*X + Y*Y ); }

dd calc(double x1,double y1,double vx1,double vy1,
        double x2,double y2,double vx2,double vy2,double r){
  double VX = (vx1-vx2), X = (x1-x2), VY = (vy1-vy2), Y = (y1-y2);
  double a = pow2(VX) + pow2(VY), b = 2*(X*VX+Y*VY), c = pow2(X) + pow2(Y) - pow2(r);
  dd ret = dd(DINF,DINF);
  double D = b*b - 4 * a * c;

  if( LT(D,0.0) ) return ret;

  if( equals(a,0.0) ) {
    if( equals(b,0.0) ) return ret;
    if( LT(-c/b,0.0)  ) return ret;
    ret.first = - c / b;
    return ret;
  }

  if( equals(D,0.0) ) D = 0;
  ret.first  = ( -b - sqrt( D ) ) / ( 2 * a );
  ret.second = ( -b + sqrt( D ) ) / ( 2 * a );
  if( !equals(ret.first,ret.second) && ret.first > ret.second ) swap(ret.first,ret.second);
  return ret;
}

const bool DEBUG = false;

int par[1000];

void init(){ rep(i,N) par[i] = i; } 

int find(int x){
  if( x==par[x])return par[x];
  return par[x] = find(par[x]);
}

void unit(int x,int y){
  x = find(x), y = find(y);
  if( x != y ) par[x] = y;
}

inline void compute2(){
  int cur[N];
  rep(i,N) knows[i] = false, cur[i] = 0;
  knows[0] = true;

  double cx[N], cy[N];
  rep(i,N) cx[i] = x[i][0], cy[i] = y[i][0];

  init();
  rep(i,N) REP(j,i+1,N) {
    double dist = getDist(x[i][0]-x[j][0],y[i][0]-y[j][0]);
    if( LTE(dist,R) ) unit(i,j);
  }
  REP(i,1,N) if( find(0) == find(i) ) knows[i] = true;

  deque<double> time_stamp;
  double prev = 0;
  rep(i,N) rep(j,size[i]) if( t[i][j] != 0 ) time_stamp.push_back(t[i][j]);
  sort(time_stamp.begin(),time_stamp.end());
  time_stamp.erase(unique(time_stamp.begin(),time_stamp.end()),time_stamp.end());  
  while( 1 ){
    double mini = 1e10;
    rep(i,N) REP(j,i+1,N) {
      if( cur[i]+1 >= size[i] || cur[j]+1 >= size[j] ) continue;
      if( knows[i] + knows[j] != 1 ) continue;
      dd res = calc(cx[i],cy[i],vx[i][cur[i]+1],vy[i][cur[i]+1],
                    cx[j],cy[j],vx[j][cur[j]+1],vy[j][cur[j]+1],R);
        
      double lower = max(t[i][cur[i]],t[j][cur[j]]);
      double upper = min(t[i][cur[i]+1],t[j][cur[j]+1]);
      assert( LTE(lower,prev) && LTE(prev,upper) );
      //cout<< "(" << res.first << "," << res.second << ")" << endl;
      if( LTE(0.0,res.first) ){
        if( LTE(lower,prev+res.first)  && LTE(prev+res.first,upper) )  mini = min(mini,prev+res.first);
      }

      if( LTE(0.0,res.second) ){
        if( LTE(lower,prev+res.second) && LTE(prev+res.second,upper) ) mini = min(mini,prev+res.second);
      }
    }

    //cout << mini << endl;

    bool initer = false;
    if( !time_stamp.empty() && LTE(time_stamp.front(),mini) ) {
      mini = time_stamp.front();
      time_stamp.pop_front();
      initer = true;
    }

    if( equals(mini,1e10) ) break;

    double tm = mini;
    
    // cout << mini << " sec " << prev << endl;
    rep(j,N){
      cx[j] += vx[j][cur[j]+1] * (tm-prev);
      cy[j] += vy[j][cur[j]+1] * (tm-prev);
      //cout << "(" << cx[j] << "," << cy[j]  << ")" << endl;
    }

    init();
    rep(j,N) if( knows[j] ) unit(0,j);

    rep(j,N)REP(k,j+1,N) {
      if( size[j] <= cur[j]+1 || size[k] <= cur[k]+1 ) continue;
      if( !( LTE(t[j][cur[j]],tm) && LTE(tm,t[j][cur[j]+1]) ) ) continue;
      if( !( LTE(t[k][cur[k]],tm) && LTE(tm,t[k][cur[k]+1]) ) ) continue;
      double dist = getDist(cx[j]-cx[k],cy[j]-cy[k]);
      //cout << j << " and " << k << " " << dist << endl;
      if( LTE(dist,R) ) unit(j,k);
    }
    REP(j,1,N) if( find(0) == find(j) ) knows[j] = true;


    //rep(i,N) cout << knows[i] << " "; cout << endl;

    rep(i,N) if( cur[i]+1 < size[i] && equals(mini,t[i][cur[i]+1]) ) cur[i]++;


    prev = mini;

    //cout << "! " << mini << endl;

  }

  vector<string> vec;
  rep(i,N) if( knows[i] ) vec.push_back(nickname[i]);
  if(!vec.empty())sort(vec.begin(),vec.end());
  rep(i,vec.size()) cout << vec[i] << endl;

}

int main(){
  while( scanf("%d%d%d",&N,&T,&R), N|T|R ){
    rep(i,N){
      cin >> nickname[i];
      cin >> t[i][0] >> x[i][0] >> y[i][0];
      vx[i][0] = vy[i][0] = 0;
      size[i] = 1;
      while( cin >> t[i][size[i]] ){
        cin >> vx[i][size[i]] >> vy[i][size[i]];
        x[i][size[i]] = x[i][size[i]-1] + vx[i][size[i]] * ( t[i][size[i]] - t[i][size[i]-1] );
        y[i][size[i]] = y[i][size[i]-1] + vy[i][size[i]] * ( t[i][size[i]] - t[i][size[i]-1] );
        ++size[i];
        if( t[i][size[i]-1] == T ) break;
      }
    }

    /*
    rep(i,N){
      cout << nickname[i] << size[i]<< " : " << endl;
      rep(j,size[i]) cout << "(" << x[i][j] << "," << y[i][j] << ":" << t[i][j] << ") ";
      cout << endl << endl;
    }
    */


    //compute();    
    compute2();    
    
  }
  return 0;
}