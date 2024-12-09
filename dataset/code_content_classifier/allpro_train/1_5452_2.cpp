#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
 
#define B 317
 
typedef long long int LLI;
#define int long long int
 
typedef pair<string, int> Pair;
typedef pair<int, int> Seg;
typedef pair<Seg, pair<int,int> > Data;
 
int size;
int T;
int n;
int m;
LLI cur;
LLI ans[200005];
LLI BIT2[100005];
vector<int> list_str;
vector<int> sorted_str;
int myrank[100010];
vector<Data> queries;
 
bool cmp_query(const Data &d1, const Data &d2) {
    int l1 = d1.first.first;
    int r1 = d1.first.second;
    int l2 = d2.first.first;
    int r2 = d2.first.second;
    
    if (l1/B != l2/B) return l1/B < l2/B;
    return r1 < r2;
}
 
void update(LLI *BIT, int k, LLI x) {
  k++;
    while (k <= n) {
        BIT[k] += x;
        k += k&-k;
    }
}
 
LLI getsum(LLI *BIT, int k) {
  k++;
    LLI ret = 0;
    while (k > 0) {
        ret += BIT[k];
        k -= k&-k;
    }
    return ret;
}
 
void append_end(int x) {
    int &ss = list_str[x];
    int idx = myrank[ss];
    cur += getsum(BIT2, n-1) - getsum(BIT2, idx); // (idx,n-1]
    update(BIT2, idx, 1);
}
void append_front(int x) {
    int &ss = list_str[x];
    int idx = myrank[ss];
    cur += getsum(BIT2, idx-1);
    update(BIT2, idx, 1);
}
void remove_end(int x) {
    int &ss = list_str[x];
    int idx = myrank[ss];
    cur -= getsum(BIT2, n-1) - getsum(BIT2, idx); // (idx,n-1]
    update(BIT2, idx, -1);
}
void remove_front(int x) {
    int &ss = list_str[x];
    int idx = myrank[ss];
    cur -= getsum(BIT2,idx-1);
    update(BIT2, idx, -1);
}
 
signed main() {
    ios_base::sync_with_stdio(false);
 
    //cin >> T;
    while (1) {
        cin >> n;
        size = 1;
        fill(BIT2, BIT2+n+1, 0ll);
 
        list_str.clear();
        sorted_str.clear();
        for (int i=0; i<n; i++) {
          int s;
          cin >> s;
          list_str.push_back(s);
          sorted_str.push_back(s);
        }
        sort(sorted_str.begin(), sorted_str.end());
        for (int i=0; i<n; i++) {
            myrank[sorted_str[i]] = i;
        }
 
        queries.clear();
        cin >> m;
        for(int j = 0 ; j < m ; j++){
            int l, r,k;
            cin >> l >> r;
            --l;
            --r;
            queries.push_back(Data(Seg(l, r), {j,j}));
      }
      
        sort(queries.begin(), queries.end(), cmp_query);
        cur = 0;
        int a = 0;
        int b = -1;
        for (int i=0; i<queries.size(); i++) {
            int l = queries[i].first.first;
            int r = queries[i].first.second;
            int idx = queries[i].second.second;
            int k = queries[i].second.first;
            while (b < r) append_end(++b);
            while (l < a) append_front(--a);
            while (a < l) remove_front(a++);
            while (r < b) remove_end(b--);
            ans[idx] = cur;
        }
 
        for (int i=0; i<m; i++) {
            cout << ans[i] << endl;
        }
        break;
    }
}  