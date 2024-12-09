#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<cassert>

#define EQ(a,b) (abs((a)-(b)) < EPS)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;

typedef long double D;
typedef complex<D> P;
typedef pair<P,P> L;
typedef pair<P,D> C;

const D PI = acos(-1);
const D EPS = 1e-10;

P unit(P p){return p / abs(p);}
pair<P,P> norm(P p){return make_pair(p*P(0,1),p*P(0,-1));}
D dot(P x,P y){return real(conj(x)*y);}
D cross(P x,P y){return imag(conj(x)*y);}


bool para(L a,L b){return abs(cross(a.fs-a.sc,b.fs-b.sc))<EPS;}

P line_cp(L a,L b){
  return a.fs+(a.sc-a.fs)*cross(b.sc-b.fs,b.fs-a.fs)/cross(b.sc-b.fs,a.sc-a.fs);
}

D seg_p_dis(L a,P x){
  if(dot(a.sc-a.fs,x-a.fs)<EPS)return abs(x-a.fs);
  if(dot(a.fs-a.sc,x-a.sc)<EPS)return abs(x-a.sc);
  return abs(cross(a.sc-a.fs,x-a.fs))/abs(a.sc-a.fs);
}


bool in_cir(C c,P x){return (abs(x-c.fs) +EPS < c.sc);}
bool on_cir(C c,P x){return EQ(abs(x-c.fs),c.sc);}

bool is_cp_cir_seg(C c, L s){
  D dis = seg_p_dis(s, c.fs);
  return (dis+EPS<c.sc);
}

vector<P> cp_cir_to_line(C a, L l){
  vector<P> v;
  P n = norm(l.fs-l.sc).fs;
  P p = line_cp(l,L(a.fs,a.fs+n));

  if(on_cir(a,p))v.pb(p);
  else if(in_cir(a,p)){
    D d = abs(a.fs-p);
    D len = sqrt(a.sc*a.sc - d*d);
    P cp_vec = len * unit(l.fs-l.sc);
    v.pb(p + cp_vec);
    v.pb(p - cp_vec);
  }
  return v;
}

vector<L> adj_line(C c, P p){
  vector<L> res;
  P a = c.fs + c.sc * unit(c.fs-p);
  vector<P> b = cp_cir_to_line(C(c.fs,abs(c.fs-p)), L(a,a+norm(c.fs-p).fs));
  rep(i,b.sz)res.pb(L(p, c.fs + c.sc * unit(c.fs-b[i])));
  return res;
}

int main(){
  int n,d;
  D x,y,r;
  C c[10];
  cin >> n >> d;
  
  rep(i,n){
    cin >> x >> y >> r;
    c[i] = C(P(x,y),r);
  }

  D res = -1.0;
  P s = P(25,0), g = P(25,94);

  L l = L(s,g);
  int cnt = 0;
  rep(i,n)cnt += is_cp_cir_seg(c[i],l);
  if(cnt <= d)res = abs(l.fs-l.sc);

  rep(i,n){
    vector<L> v1 = adj_line(c[i],s);    
    rep(j,n){
      vector<L> v2 = adj_line(c[j],g);
      rep(ii,v1.sz)rep(jj,v2.sz){
	if(para(v1[ii],v2[jj]))continue;
	P cp = line_cp(v1[ii],v2[jj]);

	if(cp.real()<EPS || cp.imag()<EPS ||
	   50.0<cp.real()+EPS || 94.0<cp.imag()+EPS)continue;
	
	L l1 = L(s,cp), l2 = L(g,cp);
	cnt = 0;
	rep(k,n)cnt += is_cp_cir_seg(c[k],l1);
	rep(k,n)cnt += is_cp_cir_seg(c[k],l2);
	rep(k,n)if(in_cir(c[k],cp))cnt--;

	if(cnt <= d){
	  D dis = abs(l1.fs-l1.sc) + abs(l2.fs-l2.sc);
	  if(res<0 || res>dis+EPS)res = dis;
	}
      }
    }
  }

  if(res<0)cout << (int)res << endl;
  else cout << fixed << setprecision(10) << res << endl;
}