#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < e; i++)
#define rep(i, n) REP(i, 0, n)

static const int MAX_N = 1000000;
static const int MAX_P = 2000000000;

int N, M, Q, S[MAX_N];

map<int, int> PM; // point map
vector<int> ATI, ATV;
vector<int> MS;
set<int> R;
vector<pair<int, int> > seg;

void init(){
  MS.clear();
  for ( set<int>::iterator it = R.begin(); it != R.end(); it++ ){
    MS.push_back(S[*it]);
  }
  sort(MS.begin(), MS.end());
}

int getCount(int r){
  seg.clear();

  if ( MS.size() > 0 ) seg.push_back(make_pair(MS[0]-r, MS[0]));

  for ( int i = 1; i < MS.size(); i++ ){
    int b = MS[i]-r;
    int e = MS[i];
    if ( b <= seg[seg.size()-1].second){
      seg[seg.size()-1].second = max(seg[seg.size()-1].second, e);
    } else {
      seg.push_back(make_pair(b, e));
    }
  }

  int cnt = 0;

  for ( int i = 0; i < seg.size(); i++ ){
    int a = distance(ATI.begin(), lower_bound(ATI.begin(), ATI.end(), max(0, seg[i].first) )) - 1;
    int b = distance(ATI.begin(), lower_bound(ATI.begin(), ATI.end(), max(0, seg[i].second) ));
    cnt += ATV[b] - ATV[a];
  }

  return cnt;
}

void bsearch(int X){
  init();

  int l = 0;
  int r = MAX_P+2000000;
  int m;
  int diff = r - l;
  int cnt = getCount(r);
  if ( cnt < X ){
    cout << "NA" << endl;
    return;
  }
  bool ok = false;
  for (int i = 0; i < 100; i++ ){
    m = (l+r)/2;
    cnt = getCount(m);
    if ( cnt >= X ){
      r = m;
      ok = true;
    } else if ( cnt < X ){
      l = m;
    }
    if ( diff == l - r ) break;
    diff = l - r;
  }
  cout << r << endl;
}

int main(){
  scanf("%d %d", &N, &Q);

  MS.clear();
  PM.clear();
  ATI.clear();
  ATV.clear();

  rep(i, N) {
    scanf("%d", &S[i]);
    PM[S[i]]++;
  }

  bool isR[MAX_N];
  rep(i, N) isR[i] = false;

  M = 0;

  ATI.push_back(-1);
  ATV.push_back(0);
  int pre = 0;
  for ( map<int, int>::iterator it = PM.begin(); it != PM.end(); it++ ){
    ATI.push_back((*it).first);
    ATV.push_back((*it).second + ATV[pre++]);
  }

  string com;
  int x;
  rep(i, Q){
    cin >> com >> x;
    if ( com[0] == 'C' ){
      bsearch(N - x);
    } else if ( com[0] == 'R' ){
      x--; // 0 base
      R.erase(R.find(x));
      M--;
    } else if ( com[0] == 'A' ){
      x--; // 0 base
      R.insert(x);
      M++;
    }
  }
}