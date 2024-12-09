#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
set<long long> have;
set<pair<long long, long long> > waiting[210000];
long long n, m, k;
struct event {
  long long type;
  long long a, b;
};
map<long long, vector<event> > events;
queue<pair<long long, long long> > people;
long long times[510000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> m;
  for (long long i = 1; i <= (k); i++) {
    long long pos;
    cin >> pos;
    have.insert(pos);
    waiting[pos].insert(pair<long long, long long>(0, i));
  }
  for (long long i = 1; i <= (m); i++) {
    event cur;
    cur.type = 1;
    long long tnow;
    cin >> tnow;
    cin >> cur.a >> cur.b;
    events[tnow].push_back(cur);
    times[i] = tnow;
  }
  long long lleft = m;
  while (lleft > 0) {
    map<long long, vector<event> >::iterator it = events.begin();
    long long tim = it->first;
    vector<event> curEvents = it->second;
    events.erase(it);
    for (auto x : curEvents) {
      if (x.type == 1) continue;
      have.insert(x.b);
      waiting[x.b].insert(pair<long long, long long>(tim, x.a));
    }
    for (auto x : curEvents) {
      if (x.type == 2) continue;
      people.push(pair<long long, long long>(x.a, x.b));
    }
    while (!people.empty() && !have.empty()) {
      pair<long long, long long> cur = people.front();
      people.pop();
      lleft--;
      set<long long>::iterator it = have.lower_bound(cur.first);
      set<long long>::iterator it2 = have.upper_bound(cur.first);
      if (it2 != have.begin()) it2--;
      long long opt1, opt2;
      if (it != have.end())
        opt1 = *it;
      else
        opt1 = 1E8;
      if (it2 != have.end())
        opt2 = *it2;
      else
        opt2 = 1E8;
      if (abs(opt1 - cur.first) < abs(opt2 - cur.first)) opt2 = opt1;
      if (abs(opt1 - cur.first) > abs(opt2 - cur.first)) opt1 = opt2;
      if (*(waiting[opt2].begin()) < *(waiting[opt1].begin())) opt1 = opt2;
      pair<long long, long long> taking = *(waiting[opt1].begin());
      waiting[opt1].erase(waiting[opt1].begin());
      event add;
      add.type = 2;
      add.a = taking.second;
      add.b = cur.second;
      events[tim + abs(cur.second - cur.first) + abs(opt1 - cur.first)]
          .push_back(add);
      cout << add.a << " ";
      cout << tim - times[m - lleft] + abs(opt1 - cur.first) << "\n";
      if (waiting[opt1].empty()) have.erase(opt1);
    }
  }
  return 0;
}
