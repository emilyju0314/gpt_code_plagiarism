#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <stack>
#include <list>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

const float PI = 3.1415926;
static const int INFTY = (1<<30);

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
map<string, ll> mp;

int main() {
  while(true) {
    cin >> n;
    if (n == 0) break;
    rep(i, n) {
      string s; ll t;
      cin >> s >> t;
      mp[s] = t;
    }

    cin >> m;
    rep(i, m) {
      int ti;
      string s;
      ll res=0;
      cin >> s >> ti;
      rep(j, ti) {
        string st;
        cin >> st;
        res += mp[st];
      }
      mp[s] = min(res, mp[s]);
    }

    string ress;
    cin >> ress;
    cout << mp[ress] << endl;
  }
  
  return 0;
}