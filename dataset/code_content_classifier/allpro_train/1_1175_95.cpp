#include <bits/stdc++.h>
using namespace std;
const int MAXn = 5e3 + 5;
int DP[MAXn][MAXn][2], Total, u, v, IN[MAXn], Leaf, Root;
int Next[MAXn << 1], End[MAXn << 1], Head[MAXn], Cur, Size[MAXn];
inline void DFS(int Temp, int Pre) {
  if (IN[Temp] == 1) {
    Size[Temp] = 1;
    DP[Temp][1][0] = 0;
    DP[Temp][0][1] = 0;
    return;
  }
  bool Jud = false;
  for (int i = Head[Temp]; i; i = Next[i]) {
    if (End[i] == Pre) continue;
    DFS(End[i], Temp);
    if (!Jud) {
      for (int j = 0; j <= Size[End[i]]; j++) {
        DP[Temp][j][0] = min(DP[End[i]][j][1] + 1, DP[End[i]][j][0]);
        DP[Temp][j][1] = min(DP[End[i]][j][0] + 1, DP[End[i]][j][1]);
      }
    } else {
      for (int j = Size[Temp] + Size[End[i]]; j >= 0; j--) {
        int Temp0 = 0x3f3f3f3f, Temp1 = 0x3f3f3f3f;
        for (int k = 0; k <= min(j, Size[End[i]]); k++) {
          Temp0 = min(Temp0, DP[Temp][j - k][0] +
                                 min(DP[End[i]][k][0], DP[End[i]][k][1] + 1));
          Temp1 = min(Temp1, DP[Temp][j - k][1] +
                                 min(DP[End[i]][k][1], DP[End[i]][k][0] + 1));
        }
        DP[Temp][j][0] = Temp0;
        DP[Temp][j][1] = Temp1;
      }
    }
    Jud = true;
    Size[Temp] += Size[End[i]];
  }
}
inline void Add_Edge(int From, int To) {
  Next[++Cur] = Head[From];
  Head[From] = Cur;
  End[Cur] = To;
}
int main() {
  scanf("%d", &Total);
  memset((DP), (0x3f), sizeof(DP));
  for (int i = 1; i < Total; i++) {
    scanf("%d %d", &u, &v);
    Add_Edge(u, v);
    Add_Edge(v, u);
    IN[u]++;
    IN[v]++;
  }
  for (int i = 1; i <= Total; i++) {
    if (IN[i] == 1) Leaf++;
    if (IN[i] > IN[Root]) Root = i;
  }
  DFS(Root, -1);
  if (Total == 2)
    printf("1\n");
  else
    printf("%d", min(DP[Root][Leaf / 2][0], DP[Root][Leaf / 2][1]));
  return 0;
}
