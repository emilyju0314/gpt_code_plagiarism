#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
class PersistentMinSegTree;
class MinSegBranch;
using seg = std::shared_ptr<PersistentMinSegTree>;

class PersistentMinSegTree {
public:
	virtual bool is_defined_at(const int position) const = 0;
	virtual int min_of_all() const = 0;
	virtual int min_of(const int from, const int to) const = 0;
	virtual seg updated(const int position, const int new_value) = 0;
};
class MinSegBranch : public PersistentMinSegTree {
	seg left, right;
	int from, to, min_cache;
public:
	MinSegBranch(int _from, int _to, const seg& _left, const seg& _right) : left{ _left }, right{ _right }, from{ _from }, to{ _to }, min_cache{ std::min(_left->min_of_all(), _right->min_of_all()) }{};
	bool is_defined_at(const int position) const override { return from <= position && position <= to; }
	int min_of_all() const override { return min_cache; }
	int min_of(const int from, const int to) const override {
		if (from <= this->from && this->to <= to) {
			return min_cache;
		}
		else if (this->from <= to && from <= this->to) {
			return std::min(left->min_of(from, to), right->min_of(from, to));
		}
		else {
			return INT_MAX;
		}
	}
	seg updated(const int position, const int new_value) override {
		if (left->is_defined_at(position)) return std::make_shared<MinSegBranch>(from, to, left->updated(position, new_value), right);
		if (right->is_defined_at(position)) return std::make_shared<MinSegBranch>(from, to, left, right->updated(position, new_value));
		throw 0;
	}
};
class MinSegLeaf : public PersistentMinSegTree {
	int position, value;
public:
	MinSegLeaf(const int _position, const int _value) : position{ _position }, value{ _value }{};
	bool is_defined_at(const int position) const override { return position == this->position; }
	int min_of_all() const override { return value; }
	int min_of(const int from, const int to) const override { return (from <= position && position <= to) ? value : INT_MAX; }
	seg updated(const int position, const int new_value) override {
		return (position == this->position) ? std::make_shared<MinSegLeaf>(position, new_value) : throw 0;
	}
};


class MinSegmentTree {
	seg root;
	static seg make(const std::vector<int>& array, const int from, const int until) {
		return (until - from == 1) ? std::shared_ptr<PersistentMinSegTree>(new MinSegLeaf(from, array[from])) : std::make_shared<MinSegBranch>(from, until - 1, make(array, from, (from + until) / 2), make(array, (from + until) / 2, until));
	}
	MinSegmentTree(seg _root) :root{ _root } {};
public:
	void copy_from(const MinSegmentTree& tree) {
		root = tree.root;
	}
	static MinSegmentTree make(const std::vector<int>& array) {
		return MinSegmentTree(make(array, 0, array.size()));
	}
	void update(int position, int new_value) {
		root = root->updated(position, new_value);
	}
	int min_of(int from, int to) const {
		return root->min_of(from, to);
	}
};
int main() {
	std::cin.tie(0); std::cin.sync_with_stdio(false);
	int n; std::cin >> n;
	std::vector<int> a(n), b(n); for (auto& i : a) std::cin >> i; for (auto& i : b) std::cin >> i;
	auto seg_a = MinSegmentTree::make(a);
	auto seg_b = MinSegmentTree::make(b);
	int q; std::cin >> q;
	for (auto _i = 0; _i < q; ++_i) {
		int x, y, z; std::cin >> x >> y >> z;
		switch (x) {
		case 1: seg_a.update(y - 1, z); break;
		case 2: seg_b.update(y - 1, z); break;
		case 3: std::cout << seg_a.min_of(y - 1, z - 1) << '\n'; break;
		case 4: std::cout << seg_b.min_of(y - 1, z - 1) << '\n'; break;
		case 5: seg_a.copy_from(seg_b); break;
		case 6: seg_b.copy_from(seg_a); break;
		default: throw 0;
		}
	}
}
