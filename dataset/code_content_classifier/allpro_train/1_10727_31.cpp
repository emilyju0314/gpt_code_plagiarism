#include<iostream>
#include<vector>
#include<cstdio>

#define REP(i,n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int s[20];
int e[20];
int d[20];

int use[20];
int c;
int f;
int n, m;
vector<int> p;

bool dfs(int pos){
  // printf("pos: %d  cnt: %d\n", pos, c);
  if(c == 0){
    p.push_back(pos);
    return true;
  }

  REP(i,m) if(use[i] && (s[i] == pos || e[i] == pos)){
    int next = (s[i] == pos ? e[i] : s[i]);

    c--;
    use[i] = false;

    if(dfs(next)){
      p.push_back(pos);
      return true;
    }

    use[i] = true;
    c++;
  }

  return false;
}

int main(){
  while(scanf("%d%d", &n, &m), n + m){
    pair<int,int> ans = make_pair(0,0);
    
    REP(i,m) scanf("%d%d%d",s+i,e+i,d+i);
    REP(i,m){ s[i]--; e[i]--; }
    
    REP(i,1<<m){
      int cnt[10] = { 0 };
      int dist = 0;
      int bad  = 0;
      
      REP(j,m) if(i & (1 << j)){
	cnt[s[j]]++;
	cnt[e[j]]++;
	dist += d[j];
      }
      
      REP(j,n) if(cnt[j] % 2 == 1) bad++;
      
      if(bad <= 2)
	ans = max(ans, make_pair(dist, i));
    }
    
    int cnt[10] = { 0 };
    int bad  = 0;
    REP(i,m) if(ans.second & (1 << i)){
      cnt[s[i]]++;
      cnt[e[i]]++;
      use[i] = (ans.second & (1 << i)) != 0;
    }
    REP(j,n) if(cnt[j] % 2 == 1) bad++;
    c = 0; REP(i,m) if(use[i]) c++;
    p = vector<int>();

    // printf("%d %d %d\n", ans.second, c, bad);
    if(bad == 0){
      REP(i,n) if(cnt[i] > 0){
	if(!dfs(f = i)) puts("error");
	break;
      }
    }else{
      REP(i,n) if(cnt[i] % 2 == 1){
	if(!dfs(f = i)) puts("error");
	break;
      }
    }

    printf("%d\n", ans.first);

    for(int i = p.size() - 1; i >= 0; i--)
      printf("%d%c", p[i] + 1, i == 0 ? '\n' : ' ');
  }

  return 0;
}