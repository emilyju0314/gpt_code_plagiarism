#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

struct SegTree {
	int n;
	struct Node {
		int64_t sum;
		int64_t add;
		int l, r;
		Node operator * (const Node &rhs) const {
			return {sum + rhs.sum, 0, l, rhs.r};
		}
	};
	std::vector<Node> nodes;
	SegTree (int n_) {
		for (n = 1; n < n_; n <<= 1);
		nodes.resize(n << 1);
		for (int i = 0; i < n; i++) nodes[i + n] = {0, 0, i, i + 1};
		for (int i = n; --i; ) nodes[i] = nodes[i << 1] * nodes[i << 1 | 1];
	}
	void flush(int node) {
		if (nodes[node].add) {
			nodes[node].sum += nodes[node].add * (nodes[node].r - nodes[node].l);
			if (node < n) {
				nodes[node << 1].add += nodes[node].add;
				nodes[node << 1 | 1].add += nodes[node].add;
			}
			nodes[node].add = 0;
		}
	}
	void add(int l, int r, int val, int node = 1) {
		flush(node);
		if (l >= nodes[node].r || r <= nodes[node].l) return;
		if (l <= nodes[node].l && r >= nodes[node].r) {
			nodes[node].add += val;
			flush(node);
		} else {
			add(l, r, val, node << 1);
			add(l, r, val, node << 1 | 1);
			nodes[node] = nodes[node << 1] * nodes[node << 1 | 1];
		}
	}
	int64_t sum(int l, int r, int node = 1) {
		flush(node);
		if (l >= nodes[node].r || r <= nodes[node].l) return 0;
		if (l <= nodes[node].l && r >= nodes[node].r) return nodes[node].sum;
		int64_t res = sum(l, r, node << 1) + sum(l, r, node << 1 | 1);
		nodes[node] = nodes[node << 1] * nodes[node << 1 | 1];
		return res;
	}
};
std::vector<std::vector<int> > hens;
std::vector<int> size;
std::vector<int> parent;
void dfs1(int i) {
	if (parent[i] != -1) hens[i].erase(std::find(hens[i].begin(), hens[i].end(), parent[i]));
	for (auto &j : hens[i]) {
		parent[j] = i;
		dfs1(j);
		size[i] += size[j];
		if (size[j] > size[hens[i][0]]) std::swap(j, hens[i][0]);
	}
}
std::vector<int> in, out, top;
int cnt = 0;
void dfs2(int i) {
	in[i] = cnt++;
	for (auto j : hens[i]) {
		top[j] = j == hens[i][0] ? top[i] : j;
		dfs2(j);
	}
	out[i] = cnt;
}
int lca(int i, int j) {
	while (1) {
		if (in[i] > in[j]) std::swap(i, j);
		if (top[i] == top[j]) return i;
		j = parent[top[j]];
	}
}
std::vector<std::pair<int, int> > descend(int high, int low) {
	std::vector<std::pair<int, int> > res;
	while (low != high) {
		int next = top[low];
		if (in[next] < in[high]) next = high;
		res.push_back({in[next] + (next == high), in[low] + 1});
		if (next == high) break;
		low = parent[next];
	}
	return res;
}


int main() {
	int n = ri(), q = ri();
	hens.resize(n);
	for (int i = 1; i < n; i++) {
		int a = ri();
		int b = ri();
		hens[a].push_back(b);
		hens[b].push_back(a);
	}
	parent.resize(n, -1);
	size.resize(n, 1);
	dfs1(0);
	in.resize(n, -1);
	out.resize(n, -1);
	top.resize(n);
	dfs2(0);
	SegTree tree(n);
	for (int i = 0; i < q; i++) {
		if (!ri()) {
			int v = ri(), x = ri();
			int lc = lca(v, x);
			int64_t res = 0;
			for (auto i : descend(lc, v)) res += tree.sum(i.first, i.second);
			for (auto i : descend(lc, x)) res += tree.sum(i.first, i.second);
			
			std::cout << res << std::endl;
		} else {
			int v = ri(), x = ri();
			tree.add(in[v] + 1, out[v], x);
		}
	}
	
	return 0;
}


