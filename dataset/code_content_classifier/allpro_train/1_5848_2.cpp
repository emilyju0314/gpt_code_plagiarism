#include <bits/stdc++.h>
using namespace std;
const int IS_ON_CYCLE = 1;
const int IS_NOT_ON_CYCLE = 0;
int find_cycle_length(int currentNode, bool* visited, int* nextNode) {
  int numberOfNodesOnCycle = 0;
  while (!visited[currentNode]) {
    visited[currentNode] = true;
    ++numberOfNodesOnCycle;
    currentNode = nextNode[currentNode];
  }
  return numberOfNodesOnCycle;
}
void find_vertices_on_cycle(int* nextNode, bool* isOnCycle, int* inDegree,
                            const int& nodes) {
  for (int i = 0; i < nodes; ++i) isOnCycle[i] = IS_ON_CYCLE;
  queue<int> q;
  while (!q.empty()) q.pop();
  for (int i = 0; i < nodes; ++i)
    if (inDegree[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    isOnCycle[u] = IS_NOT_ON_CYCLE;
    q.pop();
    --inDegree[nextNode[u]];
    if (inDegree[nextNode[u]] == 0) q.push(nextNode[u]);
  }
}
inline long long get_power_modulo(long long base, int exponent, int modulo) {
  long long res = 1LL;
  while (exponent) {
    if (exponent & 1) res = (res * base) % modulo;
    base = (base * base) % modulo;
    exponent >>= 1;
  }
  return res;
}
void compute_number_of_sets(const int& nodes, int* nextNode, bool* isOnCycle) {
  const int MOD = 1e9 + 7;
  long long result = 1LL;
  int edgesOnCycles = 0;
  bool visited[nodes];
  for (int i = 0; i < nodes; ++i) visited[i] = false;
  for (int i = 0; i < nodes; ++i)
    if (isOnCycle[i] && !visited[i]) {
      int cycleLength = find_cycle_length(i, visited, nextNode);
      edgesOnCycles += cycleLength;
      long long numberOfWaysForCycle =
          get_power_modulo(2, cycleLength, MOD) - 2;
      if (numberOfWaysForCycle < 0) numberOfWaysForCycle += MOD;
      result = (result * numberOfWaysForCycle) % MOD;
    }
  result = (result * get_power_modulo(2, nodes - edgesOnCycles, MOD)) % MOD;
  cout << result << endl;
}
void read_graph(const int& nodes, int* nextNode, int* inDegree) {
  for (int i = 0; i < nodes; ++i) inDegree[i] = 0;
  for (int i = 0; i < nodes; ++i) {
    int destination;
    cin >> destination;
    --destination;
    nextNode[i] = destination;
    ++inDegree[destination];
  }
}
int main() {
  ios::sync_with_stdio(false);
  int nodes;
  cin >> nodes;
  int nextNode[nodes];
  int inDegree[nodes];
  bool isOnCycle[nodes];
  read_graph(nodes, nextNode, inDegree);
  find_vertices_on_cycle(nextNode, isOnCycle, inDegree, nodes);
  compute_number_of_sets(nodes, nextNode, isOnCycle);
  return 0;
}
