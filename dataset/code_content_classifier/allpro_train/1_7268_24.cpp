#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
  int M, N;
  cin >> M >> N;
  vector< vector< pair<int, int> > > V(M, vector< pair<int,int> >(N,pair<int,int>(0,101)));
  for(int i = 0; i < M; ++i){
    int K;
    cin >> K;
    for(int j = 0; j < K; ++j){
      int s, t;
      string c;
      cin >> s >> c >> t;
      --s;
      if(c == ">="){
        if(V[i][s].second < t){
          cout << "No" << endl;
          return 0;
        }
        V[i][s].first = max(t, V[i][s].first);
      }else{
        if(V[i][s].first > t){
          cout << "No" << endl;
          return 0;
        }
        V[i][s].second = min(t, V[i][s].second);
      }
    }
  }
  vector< vector<bool> > G(M, vector<bool>(M,false));
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < M; ++j){
      bool f = true;
      for(int k = 0; k < N; ++k){
        if(V[i][k].first > V[j][k].second){
          f = false;
          break;
        }
      }
      G[i][j] = f;
    }
  }
  vector<int> D(M,0);
  for(int i = 0; i < M; ++i){
    bool f = true;
    for(int j = 0; j < M; ++j){
      int d = M - i;
      for(int k = 0; k < M; ++k){
        d -= G[j][k];
      }
      if(!d){
        f = false;
        for(int k = 0; k < M; ++k){
          G[j][k] = false;
          G[k][j] = false;
        }
        break;
      }
    }
    if(f){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

