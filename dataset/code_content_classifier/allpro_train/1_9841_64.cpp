#include <bits/stdc++.h>
using namespace std;
template <typename T>
void clr(stack<T>& t) {
  while (!t.empty()) t.pop();
}
vector<vector<int> > ppi;
struct scc {
  int mhsh;
  vector<vector<int> > impl;
  stack<int> whr;
  stack<int> hsn;
  stack<int> ci;
  vector<int> vst;
  vector<int> hit;
  stack<int> ts;
  vector<int> comp, psd, gvh;
  void ad(int a, int b) { impl[a].push_back(b); }
  void ini(int n) {
    mhsh = n;
    impl.resize(n);
    for (int i = 0; i < (n); ++i) impl[i].clear();
  }
  void hasol() {
    clr(whr);
    clr(hsn);
    clr(ci);
    vst.clear();
    hit.clear();
    clr(ts);
    comp.clear();
    psd.clear();
    gvh.clear();
    vst.resize(mhsh, 0);
    hit.resize(mhsh, 0);
    psd = hit;
    comp.resize(mhsh, -1);
    gvh.resize(mhsh, 0);
    int crn = 0;
    int ccp = 0;
    for (int z = 0; z < (mhsh); ++z) {
      if (vst[z]) continue;
      crn++;
      whr.push(z);
      hsn.push(0);
      vst[z] = crn;
      hit[z] = 0;
      int chit = 1;
      ci.push(0);
      int u, i, ch, v;
      while (!whr.empty()) {
        u = whr.top();
        i = ci.top();
        ch = hsn.top();
        gvh[u] = ch;
        if (!psd[u]) {
          ts.push(u);
          psd[u] = 1;
        }
        if (i == (int((impl[u]).size()))) {
          if (ch >= hit[u]) {
            while (1) {
              comp[ts.top()] = ccp;
              ts.pop();
              if (comp[u] != -1) break;
            }
            ccp++;
          }
          whr.pop();
          ci.pop();
          hsn.pop();
          continue;
        }
        v = impl[u][i];
        if (vst[v] == 0) {
          whr.push(v);
          hsn.push(chit);
          ci.push(0);
          hit[v] = chit++;
          vst[v] = crn;
          continue;
        }
        if (vst[v] == crn && comp[v] == -1) {
          if (gvh[v] < ch) {
            hsn.top() = gvh[v];
          }
        }
        ci.top()++;
      }
    }
  }
};
scc tcc;
vector<vector<int> > vid;
vector<vector<int> > tmc;
int n;
vector<string> bsst;
vector<int> valid;
vector<vector<vector<int> > > mbut;
void gencom(int pa, int pb) {
  string& a = bsst[pa];
  string& b = bsst[pb];
  vector<int>& r = mbut[pa][pb];
  r.resize((int((a).size())));
  int bstl = 0;
  int bsts = 0;
  while (bsts < (int((b).size())) && bsts < (int((a).size())) &&
         a[bsts] == b[bsts])
    ++bsts;
  r[0] = bsts;
  int cpr;
  for (int i = 1; i < (int((a).size())); ++i) {
    if (i - bstl >= bsts)
      cpr = 0;
    else
      cpr = tmc[pb][i - bstl];
    if (cpr + i < bstl + bsts) {
      r[i] = cpr;
      continue;
    }
    if (i + cpr > bstl + bsts) cpr = max(0, bstl + bsts - i);
    while (cpr < (int((b).size())) && i + cpr < (int((a).size())) &&
           a[i + cpr] == b[cpr])
      ++cpr;
    bstl = i;
    bsts = r[i] = cpr;
  }
}
bool canfit(int a, int b, int s) {
  if (s == (int((bsst[a]).size()))) return 1;
  return mbut[a][b][s] ==
         min((int((bsst[b]).size())), (int((bsst[a]).size())) - s);
}
void ad(int id) { valid.push_back(id); }
void rm(int id) {
  for (int i = 0; i < ((int((valid).size()))); ++i) {
    if (valid[i] == id) {
      for (int j = i + 1; j < (int((valid).size())); ++j)
        valid[j - 1] = valid[j];
      valid.pop_back();
      return;
    }
  }
  assert(0);
}
int nxid;
vector<int> compsz;
bool isok() {
  tcc.ini(nxid);
  int c, d;
  for (int z = 0; z < ((int((valid).size()))); ++z) {
    c = valid[z];
    for (int zz = 0; zz < ((int((valid).size()))); ++zz) {
      d = valid[zz];
      for (int j = 0; j < ((int((vid[c]).size()))); ++j) {
        if (canfit(c, d, j)) {
          if (c == d) {
            if (j == 0 || j == (int((bsst[c]).size()))) continue;
            if (j * 2 == (int((bsst[c]).size()))) return 0;
          }
          if ((int((bsst[d]).size())) + j <= (int((bsst[c]).size()))) {
            tcc.ad(vid[c][j], vid[c][j + (int((bsst[d]).size()))]);
          } else {
            tcc.ad(vid[c][j], vid[d][(int((bsst[c]).size())) - j]);
          }
        }
      }
    }
  }
  tcc.hasol();
  compsz.resize(nxid + 3);
  for (int i = 0; i < ((int((compsz).size()))); ++i) compsz[i] = 0;
  for (int z = 0; z < ((int((valid).size()))); ++z) {
    c = valid[z];
    for (int j = 0; j < ((int((vid[c]).size()))); ++j) {
      ++compsz[tcc.comp[vid[c][j]]];
    }
  }
  for (int z = 0; z < ((int((valid).size()))); ++z) {
    c = valid[z];
    for (int j = 0; j < ((int((vid[c]).size()))); ++j) {
      if (j == 0 || j == (int((bsst[c]).size()))) continue;
      if (compsz[tcc.comp[vid[c][j]]] > 1) return 0;
    }
  }
  return 1;
}
vector<int> mmc;
vector<int> p;
void genpref() {
  if ((int((p).size())) == 1) {
    mmc = {1};
    return;
  }
  int rms = 1;
  int rsz = 0;
  while (rsz < (int((p).size())) - rms && p[rsz + rms] == p[rsz]) ++rsz;
  mmc.resize((int((p).size())));
  mmc[0] = (int((p).size()));
  mmc[1] = rsz;
  for (int i = 2; i < (int((p).size())); i++) {
    mmc[i] = 0;
    if (i < rms + rsz) {
      mmc[i] = mmc[i - rms];
      if (mmc[i] + i >= rms + rsz) mmc[i] = rms + rsz - i;
    }
    if (i + mmc[i] >= rms + rsz) {
      rms = i;
      rsz = mmc[i];
      while (rsz < (int((p).size())) - rms && p[rsz + rms] == p[rsz]) ++rsz;
      mmc[i] = rsz;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  tmc.resize(n);
  bsst.resize(n);
  vid.resize(n);
  nxid = 0;
  mbut.resize(n, vector<vector<int> >(n));
  for (int i = 0; i < (n); ++i) {
    cin >> bsst[i];
    p.resize((int((bsst[i]).size())));
    for (int j = 0; j < ((int((bsst[i]).size()))); ++j) p[j] = int(bsst[i][j]);
    genpref();
    tmc[i] = mmc;
    vid[i].resize((int((bsst[i]).size())) + 1);
    for (int j = 0; j < ((int((vid[i]).size()))); ++j) vid[i][j] = nxid++;
  }
  tcc.ini(nxid);
  int sm = 0;
  int nxad = 0;
  int nxrm = 0;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) gencom(i, j);
  }
  while (1) {
    if (nxad == n) break;
    ad(nxad++);
    while (!isok()) rm(nxrm++);
    sm += nxad - nxrm;
  }
  cout << sm << endl;
  return 0;
}
