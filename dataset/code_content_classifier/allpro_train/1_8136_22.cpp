#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;

int main() {
  int a, n, m;
  scanf("%d", &a);
  vector< Pi > datas;
  for(int i = 0; i < a; i++) {
    int H1, H2, M1, M2;
    scanf("%d:%d-%d:%d", &H1, &M1, &H2, &M2);
    datas.push_back(make_pair(H1 * 60 + M1, H2 * 60 + M2));
  }
  scanf("%d", &n);
  vector< vector< Pi > > teacher(n);
  for(int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    while(k--){
      int H1, H2, M1, M2;
      scanf("%d:%d-%d:%d", &H1, &M1, &H2, &M2);
      teacher[i].push_back(make_pair(H1 * 60 + M1, H2 * 60 + M2));
    }
  }
  scanf("%d", &m);
  vector< vector< Pi > > student(m);
  for(int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    while(k--){
      int H1, H2, M1, M2;
      scanf("%d:%d-%d:%d", &H1, &M1, &H2, &M2);
      student[i].push_back(make_pair(H1 * 60 + M1, H2 * 60 + M2));
    }
  }

  int ret = 0;
  for(int i = 0; i < a; i++) {
    int t = 0, s = 0;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < teacher[j].size(); k++){
        if(teacher[j][k].first <= datas[i].first && datas[i].second <= teacher[j][k].second) {
          ++t;
          break;
        }
      }
    }
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < student[j].size(); k++){
        if(student[j][k].first <= datas[i].first && datas[i].second <= student[j][k].second) {
          ++s;
          break;
        }
      }
    }
    ret += min(t, s);
  }
  printf("%d\n", ret);
}