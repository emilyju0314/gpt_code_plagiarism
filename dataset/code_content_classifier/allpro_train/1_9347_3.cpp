#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define EQ(a,b) (abs((a)-(b))<EPS)
#define chmin(a,b) (a) = min((a),(b))
#define chmax(a,b) (a) = max((a),(b))
using namespace std;
typedef double D;
const D EPS = 1e-8;

struct elevator{
  int cap,rem;
  D v,ts,pos,stop;
  elevator(int a,D b,D c,D d):
    cap(a),v(b),ts(c),pos(d){rem = a; stop=-1;}
  
  D reachTime(D goal){
    if(stop>-EPS)return ts - stop;
    if(rem == 0)return pos/v;
    return abs(goal - pos)/v;
  }

  int move(D goal, D t){
    if(stop>-EPS){
      stop += t;
      if(EQ(stop,ts))stop = -1;
      return 0;
    }

    if(rem==0)goal = 0;
    pos += (goal>pos)?v*t:-v*t;
    if(EQ(goal,pos)){
      stop = 0;
      if(EQ(pos,0)){
	int res = cap-rem;
	rem = cap;
	return res;
      }
    }
    return 0;
  }
};

int main(){
  int N,M;

  while(cin >> N >> M, N){
    D d;
    cin >> d;
    bool flag = false;

    vector<int> device(N);
    rep(i,N)cin >> device[i];

    vector<elevator> el;
    rep(i,M){
      int c,v,ts,x;
      cin >> c >> v >> ts >> x;
      el.push_back(elevator(c,v,ts,d*(x-1)));
    }

    D k,tx,ty,tz;
    cin >> k >> tx >> ty >> tz; k--;
    vector<D> burn(N,-1);
    burn[k] = tx;
    int uf = k+1, df = k-1;
    D nxtu = ty, nxtd = tz;

    int ans = device[0];
    D curTime = 0, lastTime = 0;
    for(;;){
      int goal = -1;
      rep(i,N)if(device[i])goal = i;
      if(goal<1)break;

      D nxtTime = 1e9;
      rep(i,N){
	if(burn[i]>-EPS)chmin(nxtTime, burn[i]);
      }
      if(uf<N)chmin(nxtTime,nxtu);
      if(df>=0)chmin(nxtTime,nxtd);

      rep(i,M)chmin(nxtTime, el[i].reachTime(d*goal) );

      curTime += nxtTime;

      rep(i,N){
	if(burn[i]>-EPS){
	  burn[i] -= nxtTime;
	  if(EQ(burn[i],0)){
	    device[i] = 0;
	    burn[i] = -1;
	  }
	}
      }

      nxtu -= nxtTime;
      if(EQ(nxtu,0)){
	if(uf<N)burn[uf] = tx;
	uf++; nxtu = ty;
      }

      nxtd -= nxtTime;
      if(EQ(nxtd,0)){
	if(df>=0)burn[df] = tx;
	df--; nxtd = tz;
      }

      rep(i,M){
	int num = el[i].move(d*goal,nxtTime);
	if(num){
	  ans += num; chmax(lastTime, curTime + el[i].ts);
	}

	if(EQ(el[i].pos,d*goal) && EQ(el[i].stop,0)){
	  int tmp = min(el[i].rem, device[goal]);
	  el[i].rem -= tmp; device[goal] -= tmp;
	  if(tmp && goal)flag = true;
	}
      }
    }

    rep(i,M){
      if(el[i].rem != el[i].cap){
	ans += el[i].cap - el[i].rem;
	D nxtTime = el[i].pos/el[i].v + el[i].ts;
	if(el[i].stop>-EPS)nxtTime += el[i].ts-el[i].stop;
        chmax(lastTime, curTime + nxtTime);
      }
    }
    cout << fixed << setprecision(6) << ans << " "
      	 << (flag?lastTime:0.0) << endl;
  }
}