#include<bits/stdc++.h>

#define EQ(a,b) (abs((a)-(b)) < EPS)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef long double D;
typedef complex<D> P;
typedef pair<P,P> Line;
typedef vector<P> Poly;

const D EPS = 1e-8;
const D PI = acos(-1);
const D sq2 = 1.0/sqrt(2.0);

inline D dot(P x, P y){return real(conj(x)*y);}
inline D cross(P x, P y){return imag(conj(x)*y);}
inline P rotate(P v, D s){
  return P(real(v)*cos(s) - imag(v)*sin(s), real(v)*sin(s) + imag(v)*cos(s) );
}

int ccw(P a,P b,P c){
  b -= a;c -= a;
  if (cross(b,c)>EPS) return 1;   //counter clockwise
  if (cross(b,c)<-EPS) return -1; //clockwise
  if (dot(b, c)<-EPS) return 2;   //c--a--b on line
  if (abs(b)+EPS<abs(c)) return -2;   //a--b--c on line
  return 0;                       //on segment
}

inline bool para(Line a,Line b){return abs(cross(a.fs-a.sc,b.fs-b.sc))<EPS;}

inline P line_cp(Line a,Line b){
  return a.fs+(a.sc-a.fs)*cross(b.sc-b.fs,b.fs-a.fs)/cross(b.sc-b.fs,a.sc-a.fs);
}

inline bool is_cp(Line a,Line b){
  if(ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0)
    if(ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0)return true;
  return false;
}

vector<D> solve(D a, D b, D c){
  vector<D> res;
  if(EQ(a,0)){
    if(EQ(b,0))return res;
    res.pb(-c/b); return res;
  }

  D d = b*b - 4*a*c;
  if(EQ(d,0)){
    res.pb(-b/2/a); return res;
  }
  if(d<EPS)return res;

  d = sqrt(d);
  res.pb( (-b-d)/2/a ); res.pb( (-b+d)/2/a );
  return res;
}

int main(){
  D Time,R;
  int L,M,N;
  P pm[55], vm[55], pg[55], vg[55];
  D tm[55], tg[55];
  Poly obj[55];

  cin.tie(0);
  std::ios::sync_with_stdio(false);
  while(cin >> Time >> R){
    if(EQ(Time,0) && EQ(R,0))break;

    cin >> L;
    rep(i,L){
      D x,y;
      cin >> x >> y >> tm[i];
      pm[i] = P(x,y);
    }
    rep(i,L-1)vm[i] = (pm[i+1] - pm[i]) / (tm[i+1] - tm[i]);

    cin >> M;
    rep(i,M){
      D x,y;
      cin >> x >> y >> tg[i];
      pg[i] = P(x,y);
    }
    rep(i,M-1)vg[i] = (pg[i+1] - pg[i]) / (tg[i+1] - tg[i]);

    cin >> N;
    rep(i,N){
      D xl, yb, xr, yt;
      cin >> xl >> yb >> xr >> yt;
      if(xl > xr)swap(xl,xr);
      if(yb > yt)swap(yb,yt);

      obj[i].clear();
      obj[i].pb(P(xl,yb)); obj[i].pb(P(xr,yb));
      obj[i].pb(P(xr,yt)); obj[i].pb(P(xl,yt));
    }

    vector<D> turn, event;
    rep(i,L)turn.pb(tm[i]);
    rep(i,M)turn.pb(tg[i]);
    sort(all(turn));
    turn.erase(unique(all(turn)),turn.end());

    event = turn;

    //list all event time
    int sm=0, sg=0;
    rep(t,turn.sz-1){
      if(sm<L && EQ(tm[sm+1], turn[t]))sm++;
      if(sg<M && EQ(tg[sg+1], turn[t]))sg++;

      P curM = P(vm[sm].real() * (turn[t]-tm[sm]) + pm[sm].real(),
		 vm[sm].imag() * (turn[t]-tm[sm]) + pm[sm].imag() );
      P curG = P(vg[sg].real() * (turn[t]-tg[sg]) + pg[sg].real(),
		 vg[sg].imag() * (turn[t]-tg[sg]) + pg[sg].imag() );
      
      D va = vm[sm].real(), ua = vm[sm].imag();
      D vb = vg[sg].real(), ub = vg[sg].imag();

      D v = va-vb, u = ua-ub;
      D x = curM.real()-curG.real(), y = curM.imag()-curG.imag();

      //distance is no more than R
      {
	D a = v*v+u*u, b = 2.0*(v*x+u*y), c = x*x+y*y-R*R;

	vector<D> ts = solve(a,b,c);
	rep(k,ts.sz){
	  if(ts[k] < -EPS || ts[k] > (turn[t+1]-turn[t])+EPS)continue;
	  event.pb(ts[k] + turn[t]);
	}
      }

      //angle is no more than 45 degree
      {
        P vec = rotate(vg[sg], PI/4);
	D b = v*vec.imag() - u*vec.real(), c = x*vec.imag() - y*vec.real();
	
	vector<D> ts = solve(0,b,c);
	rep(k,ts.sz){
	  if(ts[k] < -EPS || ts[k] > (turn[t+1]-turn[t])+EPS)continue;
	  event.pb(ts[k] + turn[t]);
	}
      }

      {
        P vec = rotate(vg[sg], -PI/4);
	D b = v*vec.imag() - u*vec.real(), c = x*vec.imag() - y*vec.real();

	vector<D> ts = solve(0,b,c);
	rep(k,ts.sz){
	  if(ts[k] < -EPS || ts[k] > (turn[t+1]-turn[t])+EPS)continue;
	  event.pb(ts[k] + turn[t]);
	}
      }

      //hit corner of obstacles
      rep(i,N){
	rep(j,obj[i].sz){
	  D xa = curM.real() - obj[i][j].real(), ya = curM.imag() - obj[i][j].imag();
	  D xb = curG.real() - obj[i][j].real(), yb = curG.imag() - obj[i][j].imag();

	  D a = va*ub - ua*vb;
	  D b = va*yb + ub*xa -ua*xb -vb*ya;
	  D c = xa*yb - ya*xb;

	  vector<D> ts = solve(a,b,c);
	  rep(k,ts.sz){
	    if(ts[k] < -EPS || ts[k] > (turn[t+1]-turn[t])+EPS)continue;
	    event.pb(ts[k] + turn[t]);
	  }
	}
      } 
    }

    sort(all(event));
    event.erase(unique(all(event)),event.end());

    D ans = 0;
    sm = 0; sg = 0;
    rep(t,event.sz-1){
      D T = (event[t] + event[t+1])/2;
      if(sm<L && EQ(tm[sm+1], event[t]))sm++;
      if(sg<M && EQ(tg[sg+1], event[t]))sg++;

      //check
      bool f = true;
      P curM = P(vm[sm].real() * (T-tm[sm]) + pm[sm].real(),
		 vm[sm].imag() * (T-tm[sm]) + pm[sm].imag() );
      P curG = P(vg[sg].real() * (T-tg[sg]) + pg[sg].real(),
		 vg[sg].imag() * (T-tg[sg]) + pg[sg].imag() );

      if(abs(curM-curG) > R+EPS)f = false;
      else{
	P A = pg[sg+1]-curG, B = curM-curG;
	if(dot(A,B)/abs(A)/abs(B) +EPS < sq2)f = false;
	else{
	  Line eye = Line(curM, curG);
	  rep(i,N){
	    rep(j,obj[i].sz){
	      Line wall = Line( obj[i][j], obj[i][(j+1)%obj[i].sz] );
	      if(is_cp(eye, wall)){
		f = false; break;
	      }
	      if(!f)break;
	    }
	  }
	}
      }

      if(f)ans += event[t+1]-event[t];
    }

    cout << fixed << setprecision(12) << ans << endl;
  }
}