#include <bits/stdc++.h>
using namespace std;
int operations_made = 0;
vector<int> get_centroids(vector<vector<int> >& node_idx___neigh_idxes) {
  int nodes_nr = node_idx___neigh_idxes.size();
  vector<vector<int> > node_idx___children(nodes_nr);
  vector<int> node_idx___is_visited(nodes_nr, 0);
  stack<int> dfs_stack;
  dfs_stack.push(0);
  node_idx___is_visited[0] = 1;
  while (!dfs_stack.empty()) {
    int curr_node_idx = dfs_stack.top();
    dfs_stack.pop();
    for (auto neigh_idx : node_idx___neigh_idxes[curr_node_idx]) {
      if (!node_idx___is_visited[neigh_idx]) {
        node_idx___is_visited[neigh_idx] = 1;
        node_idx___children[curr_node_idx].push_back(neigh_idx);
        dfs_stack.push(neigh_idx);
      }
    }
  }
  vector<int> node_idx___subnodes_nr(nodes_nr, 1);
  for (auto& is_visited : node_idx___is_visited) {
    is_visited = 0;
  }
  dfs_stack.push(0);
  node_idx___is_visited[0] = 1;
  while (!dfs_stack.empty()) {
    int curr_node_idx = dfs_stack.top();
    bool all_children_visited = true;
    for (auto child_idx : node_idx___children[curr_node_idx]) {
      if (!node_idx___is_visited[child_idx]) {
        node_idx___is_visited[child_idx] = 1;
        dfs_stack.push(child_idx);
        all_children_visited = false;
      }
    }
    if (all_children_visited) {
      for (auto child_idx : node_idx___children[curr_node_idx]) {
        node_idx___subnodes_nr[curr_node_idx] +=
            node_idx___subnodes_nr[child_idx];
      }
      dfs_stack.pop();
    }
  }
  vector<int> centroids;
  for (int node_idx = 0; node_idx < nodes_nr; node_idx += 1) {
    bool is_centroid = true;
    int parent_subnodes = nodes_nr - 1;
    for (auto child_idx : node_idx___children[node_idx]) {
      if (node_idx___subnodes_nr[child_idx] > nodes_nr / 2) {
        is_centroid = false;
        break;
      }
      parent_subnodes -= node_idx___subnodes_nr[child_idx];
    }
    if (parent_subnodes > nodes_nr / 2) {
      is_centroid = false;
    }
    if (is_centroid) {
      centroids.push_back(node_idx);
    }
  }
  return centroids;
}
pair<int, int> straighten_subtree(int stone_idx, int curr_root_idx,
                                  vector<set<int> >& node_idx___neigh_idxes) {
  int neigh_nr = node_idx___neigh_idxes[curr_root_idx].size();
  if (neigh_nr == 1) {
    return make_pair(curr_root_idx, curr_root_idx);
  }
  vector<pair<int, int> > rel_neigh_idx___root__hangler;
  set<int> curr_neigh_idxes = node_idx___neigh_idxes[curr_root_idx];
  for (auto& neigh_idx : curr_neigh_idxes) {
    if (neigh_idx != stone_idx) {
      rel_neigh_idx___root__hangler.push_back(
          straighten_subtree(curr_root_idx, neigh_idx, node_idx___neigh_idxes));
    }
  }
  int curr_parent_idx = stone_idx;
  int next_root_idx =
      (neigh_nr == 2 ? curr_root_idx : rel_neigh_idx___root__hangler[0].second);
  if (next_root_idx != curr_root_idx) {
    node_idx___neigh_idxes[stone_idx].insert(
        rel_neigh_idx___root__hangler[0].second);
    auto it = node_idx___neigh_idxes[stone_idx].find(curr_root_idx);
    node_idx___neigh_idxes[stone_idx].erase(it);
    it = node_idx___neigh_idxes[curr_root_idx].find(stone_idx);
    node_idx___neigh_idxes[curr_root_idx].erase(it);
    node_idx___neigh_idxes[rel_neigh_idx___root__hangler[0].second].insert(
        stone_idx);
    curr_parent_idx = rel_neigh_idx___root__hangler[0].first;
    printf("%d %d %d\n", stone_idx + 1, curr_root_idx + 1,
           rel_neigh_idx___root__hangler[0].second + 1);
    operations_made++;
  }
  neigh_nr = rel_neigh_idx___root__hangler.size();
  for (int neigh_idx = 1; neigh_idx < neigh_nr - 1; neigh_idx += 1) {
    printf("%d %d %d\n", curr_parent_idx + 1, curr_root_idx + 1,
           rel_neigh_idx___root__hangler[neigh_idx].second + 1);
    operations_made++;
    node_idx___neigh_idxes[curr_parent_idx].insert(
        rel_neigh_idx___root__hangler[neigh_idx].second);
    node_idx___neigh_idxes[rel_neigh_idx___root__hangler[neigh_idx].second]
        .insert(curr_parent_idx);
    auto it = node_idx___neigh_idxes[curr_parent_idx].find(curr_root_idx);
    node_idx___neigh_idxes[curr_parent_idx].erase(it);
    it = node_idx___neigh_idxes[curr_root_idx].find(curr_parent_idx);
    node_idx___neigh_idxes[curr_root_idx].erase(it);
    curr_parent_idx = rel_neigh_idx___root__hangler[neigh_idx].first;
  }
  return make_pair(next_root_idx,
                   rel_neigh_idx___root__hangler[neigh_nr - 1].second);
}
int hedgehogify(int stone_idx, int curr_root_idx,
                vector<set<int> >& node_idx___neigh_idxes) {
  int neigh_nr = node_idx___neigh_idxes[curr_root_idx].size();
  if (neigh_nr == 1) {
    return curr_root_idx;
  }
  int center_idx = curr_root_idx;
  for (auto neigh_idx : node_idx___neigh_idxes[curr_root_idx]) {
    if (neigh_idx != stone_idx) {
      center_idx =
          hedgehogify(curr_root_idx, neigh_idx, node_idx___neigh_idxes);
    }
  }
  printf("%d %d %d\n", stone_idx + 1, curr_root_idx + 1, center_idx + 1);
  operations_made++;
  return center_idx;
}
int straighten_and_hedgehogify_parts(
    vector<vector<int> >& node_idx___neigh_idxes, int centroid1, int centroid2,
    bool fl) {
  int nodes_nr = node_idx___neigh_idxes.size();
  int neutral_idx = centroid1;
  vector<set<int> > curr_node_idx___neigh_idxes(nodes_nr);
  vector<int> curr_node_idx___is_visited(nodes_nr, 0);
  for (auto neigh_idx : node_idx___neigh_idxes[centroid1]) {
    if ((neigh_idx == centroid2) || (neigh_idx == centroid1)) {
      continue;
    }
    curr_node_idx___neigh_idxes[centroid1].insert(neigh_idx);
    curr_node_idx___neigh_idxes[neigh_idx].insert(centroid1);
    stack<int> dfs_stack;
    dfs_stack.push(neigh_idx);
    curr_node_idx___is_visited[neigh_idx] = 1;
    while (!dfs_stack.empty()) {
      int curr_node_idx = dfs_stack.top();
      dfs_stack.pop();
      for (auto curr_neigh_idx : node_idx___neigh_idxes[curr_node_idx]) {
        if ((curr_neigh_idx != centroid1) &&
            (curr_node_idx___is_visited[curr_neigh_idx] == 0) &&
            (curr_neigh_idx != centroid2)) {
          curr_node_idx___neigh_idxes[curr_node_idx].insert(curr_neigh_idx);
          curr_node_idx___neigh_idxes[curr_neigh_idx].insert(curr_node_idx);
          curr_node_idx___is_visited[curr_neigh_idx] = 1;
          dfs_stack.push(curr_neigh_idx);
        }
      }
    }
    pair<int, int> report =
        straighten_subtree(centroid1, neigh_idx, curr_node_idx___neigh_idxes);
    neutral_idx =
        hedgehogify(centroid1, report.first, curr_node_idx___neigh_idxes);
  }
  if (centroid1 == centroid2) {
    return neutral_idx;
  }
  if (!fl) {
    neutral_idx = straighten_and_hedgehogify_parts(node_idx___neigh_idxes,
                                                   centroid2, centroid1, 1);
  }
  return neutral_idx;
}
void solve() {
  int nodes_nr = 0;
  scanf("%d", &nodes_nr);
  vector<vector<int> > node_idx___neigh_idxes(nodes_nr);
  for (int edge_idx = 0; edge_idx < nodes_nr - 1; edge_idx += 1) {
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    node1--;
    node2--;
    node_idx___neigh_idxes[node2].push_back(node1);
    node_idx___neigh_idxes[node1].push_back(node2);
  }
  vector<int> centroids = get_centroids(node_idx___neigh_idxes);
  int centroid1, centroid2;
  if (centroids.size() == 1) {
    centroid1 = centroids[0];
    centroid2 = centroids[0];
  } else {
    centroid1 = centroids[0];
    centroid2 = centroids[1];
  }
  vector<vector<int> > operations;
  printf("%d\n", 2 * nodes_nr);
  int neigh_idx = straighten_and_hedgehogify_parts(node_idx___neigh_idxes,
                                                   centroid1, centroid2, 0);
  while (operations_made < 2 * nodes_nr) {
    printf("%d %d %d\n", centroid2 + 1, neigh_idx + 1, neigh_idx + 1);
    operations_made++;
  }
}
int main() { solve(); }
