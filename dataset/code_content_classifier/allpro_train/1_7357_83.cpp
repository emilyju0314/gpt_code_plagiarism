#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;

vector<int> way[SIZE];
bool visited[SIZE];
int id[SIZE];
int counter[2];

bool dfs(int now, int f){
  if(visited[now]){
    return id[now] == f;
  }

  visited[now] = true;
  id[now] = f;
  counter[f]++;
  
  for(int i=0;i<(int)way[now].size();i++)
    if(dfs(way[now][i], !f) == false) return false;

  return true;
}

bool solve(){
  int n, m;
  int a, b;

  scanf("%d%d", &n, &m);

  if(n == 0)return false;
  
  for(int i=0;i<n;i++) way[i] = vector<int>();
  memset(visited, 0, sizeof(visited));
  counter[0] = counter[1] = 0;  
  
  for(int i=0;i<m;i++){
    scanf("%d%d", &a, &b);
    a--; b--;

    way[a].push_back(b);
    way[b].push_back(a);
  }

  if(!dfs(0,0)){
    puts("0");
  }else{
    //cerr << counter[0] << " " << counter[1] << endl;
    if(counter[0] > counter[1]) swap(counter[0] , counter[1]);

    vector<int> vec;
    
    if(counter[0]%2==0){
      vec.push_back(counter[0]/2);
    }

    if(counter[0] != counter[1] && counter[1]%2 == 0){
      vec.push_back(counter[1]/2);
    }

    printf("%d\n", (int)vec.size());
    
    for(int i=0;i<vec.size();i++){
      printf("%d\n", vec[i]);
    }
  }
  
  return true;
}

int main(){
  while(solve());
}


