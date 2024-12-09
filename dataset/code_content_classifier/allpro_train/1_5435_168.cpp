#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

int fir[N] , ne[M] , to[M] , cnt , x , y , A[N] , B[N] , fa[N] , id[N] , n , m;
long long S[N] , More[N];

void add(int x , int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

void link(int x , int y) {
  add(x , y);
  add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int getf(int x) {
  return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));
}

bool cmp(int x , int y) {
  return A[x] < A[y];
}

bool vis[N];

int main() {
  scanf("%d%d" , &n , &m);
  int it = 0;
  for(int i = 1;i <= n;++ i) {
    scanf("%d%d" , &A[i] , &B[i]);
    More[i] = A[i] = max(0 , A[i] - B[i]);
    fa[i] = id[i] = i;
    S[i] = B[i];
  }
  for(int i = 1;i <= m;++ i) {
    scanf("%d%d" , &x , &y);
    link(x , y);
  }
  sort(id + 1 , id + n + 1 , cmp);
  for(int i = 1;i <= n;++ i) {
    int x = id[i];
    vis[x] = 1;
    Foreachson(j , x) {
      int V = to[j];
      if(!vis[V])
	continue;
      int a = getf(x) , b = getf(V);
      if(a == b)
	continue;
      fa[b] = a; S[a] += S[b];
      More[a] = min(More[a] , More[b] + max(0LL , A[x] - More[b] - S[b]));
    }
  }
  int now = getf(1);
  cout << S[now] + More[now] << endl;
}
