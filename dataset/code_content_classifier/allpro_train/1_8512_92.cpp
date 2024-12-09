#include <bits/stdc++.h>
using namespace std;
map<long long int, vector<long long int> > m;
map<long long int, vector<long long int> >::iterator it;
map<long long int, pair<long long int, long long int> > keep;
map<long long int, pair<long long int, long long int> > keep2;
map<long long int, pair<long long int, long long int> >::iterator pt;
map<long long int, pair<long long int, long long int> >::iterator gt;
map<pair<long long int, long long int>, vector<long long int> > idx;
map<pair<long long int, long long int>, long long int> hold;
vector<long long int> storing1;
vector<long long int> storing2;
int main() {
  long long int cce;
  long long int sumVale;
  long long int nodeVale;
  long long int n;
  long long int i;
  long long int l;
  long long int clr;
  long long int sz;
  long long int j;
  long long int val;
  long long int prev;
  long long int prevNode;
  long long int now;
  long long int nowNode;
  long long int ans;
  long long int cc, cc2;
  long long int sumVal, sumVal2;
  long long int nodeVal, nodeVal2;
  long long int ccf, ccf2;
  long long int sumValf, sumValf2;
  long long int nodeValf, nodeValf2;
  long long int color1;
  long long int color2;
  m.clear();
  keep.clear();
  keep2.clear();
  idx.clear();
  hold.clear();
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> clr >> sz;
    m[clr].push_back(sz);
    idx[pair<long long int, long long int>(clr, sz)].push_back(i);
    hold[pair<long long int, long long int>(clr, sz)]++;
  }
  for (it = m.begin(); it != m.end(); it++) {
    sort((*it).second.begin(), (*it).second.end(), greater<long long int>());
    l = (*it).second.size();
    val = 0;
    for (j = 0; j < l; j++) {
      val = val + (*it).second[j];
      pt = keep.find(j + 1);
      if (pt == keep.end())
        keep[j + 1] = pair<long long int, long long int>(val, (*it).first);
      else {
        prev = keep[j + 1].first;
        prevNode = keep[j + 1].second;
        gt = keep2.find(j + 1);
        if (gt == keep2.end()) {
          if (val > prev) {
            keep[j + 1] = pair<long long int, long long int>(val, (*it).first);
            keep2[j + 1] = pair<long long int, long long int>(prev, prevNode);
          } else
            keep2[j + 1] = pair<long long int, long long int>(val, (*it).first);
        } else {
          now = keep2[j + 1].first;
          nowNode = keep2[j + 1].second;
          if (val > prev) {
            keep[j + 1] = pair<long long int, long long int>(val, (*it).first);
            keep2[j + 1] = pair<long long int, long long int>(prev, prevNode);
          } else if (val > now) {
            keep2[j + 1] = pair<long long int, long long int>(val, (*it).first);
          }
        }
      }
    }
  }
  ans = 0;
  for (pt = keep.begin(); pt != keep.end(); pt++) {
    cc = (*pt).first;
    sumVal = (*pt).second.first;
    nodeVal = (*pt).second.second;
    cce = -1;
    sumVale = -1;
    nodeVale = -1;
    gt = keep2.find(cc);
    if (gt != keep2.end()) {
      cc2 = (*gt).first;
      sumVal2 = (*gt).second.first;
      nodeVal2 = (*gt).second.second;
      cce = cc2;
      sumVale = sumVal2;
      nodeVale = nodeVal2;
      if (sumVal + sumVal2 > ans) {
        ans = sumVal + sumVal2;
        color1 = nodeVal;
        color2 = nodeVal2;
      }
    }
    gt = keep.find(cc + 1);
    if (gt != keep.end()) {
      cc2 = (*gt).first;
      sumVal2 = (*gt).second.first;
      nodeVal2 = (*gt).second.second;
      if (nodeVal != nodeVal2) {
        if (sumVal + sumVal2 > ans) {
          ans = sumVal + sumVal2;
          color1 = nodeVal;
          color2 = nodeVal2;
        }
      } else {
        if (cce != -1 && nodeVale != nodeVal2) {
          if (sumVale + sumVal2 > ans) {
            ans = sumVale + sumVal2;
            color1 = nodeVale;
            color2 = nodeVal2;
          }
        }
        gt = keep2.find(cc + 1);
        if (gt != keep2.end()) {
          if (sumVal + (*gt).second.first > ans) {
            ans = sumVal + (*gt).second.first;
            color1 = nodeVal;
            color2 = (*gt).second.second;
          }
        }
      }
    }
  }
  long long int ll1;
  long long int ll2;
  long long int ccc = 0;
  long long int flag = 0;
  long long int toPrint;
  long long int use;
  vector<long long int> v1;
  vector<long long int> v2;
  v1 = m[color1];
  v2 = m[color2];
  ll1 = v1.size();
  ll2 = v2.size();
  cout << ans << endl;
  if (ll1 != ll2)
    cout << 2 * min(ll1, ll2) + 1 << endl;
  else
    cout << 2 * ll1 << endl;
  if (ll1 <= ll2) {
    for (i = 0; i < ll1; i++) {
      use = hold[pair<long long int, long long int>(color1, v1[i])];
      hold[pair<long long int, long long int>(color1, v1[i])]--;
      toPrint = idx[pair<long long int, long long int>(color1, v1[i])][use - 1];
      storing1.push_back(toPrint + 1);
      use = hold[pair<long long int, long long int>(color2, v2[i])];
      hold[pair<long long int, long long int>(color2, v2[i])]--;
      toPrint = idx[pair<long long int, long long int>(color2, v2[i])][use - 1];
      storing2.push_back(toPrint + 1);
    }
    if (ll1 < ll2) {
      use = hold[pair<long long int, long long int>(color2, v2[i])];
      hold[pair<long long int, long long int>(color2, v2[i])]--;
      toPrint = idx[pair<long long int, long long int>(color2, v2[i])][use - 1];
      storing2.push_back(toPrint + 1);
    }
  } else {
    for (i = 0; i < ll2; i++) {
      use = hold[pair<long long int, long long int>(color2, v2[i])];
      hold[pair<long long int, long long int>(color2, v2[i])]--;
      toPrint = idx[pair<long long int, long long int>(color2, v2[i])][use - 1];
      storing2.push_back(toPrint + 1);
      use = hold[pair<long long int, long long int>(color1, v1[i])];
      hold[pair<long long int, long long int>(color1, v1[i])]--;
      toPrint = idx[pair<long long int, long long int>(color1, v1[i])][use - 1];
      storing1.push_back(toPrint + 1);
    }
    use = hold[pair<long long int, long long int>(color1, v1[i])];
    hold[pair<long long int, long long int>(color1, v1[i])]--;
    toPrint = idx[pair<long long int, long long int>(color1, v1[i])][use - 1];
    storing1.push_back(toPrint + 1);
  }
  sort(storing1.begin(), storing1.end(), greater<long long int>());
  sort(storing2.begin(), storing2.end(), greater<long long int>());
  if (ll1 <= ll2) {
    while (1) {
      if (ccc >= ll1) break;
      if (flag == 0) {
        cout << storing2[ccc];
        flag = 1;
      } else if (flag == 1) {
        cout << " " << storing2[ccc];
      }
      if (flag == 0) {
        cout << storing1[ccc];
      } else
        cout << " " << storing1[ccc];
      ccc++;
    }
    if (ll1 < ll2) {
      cout << " " << storing2[ccc];
    }
  } else {
    ccc = 0;
    while (1) {
      if (ccc >= ll2) break;
      if (flag == 0) {
        cout << storing1[ccc];
        flag = 1;
      } else if (flag == 1) {
        cout << " " << storing1[ccc];
      }
      if (flag == 0) {
        cout << storing2[ccc];
      } else
        cout << " " << storing2[ccc];
      ccc++;
    }
    cout << " " << storing1[ccc];
  }
  cout << endl;
  return 0;
}
