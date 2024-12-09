#include <bits/stdc++.h>

using namespace std;

const long long OO = INT_MAX;

class SegmentTree
{
	int n;
	vector<long long> tree, delta;

	void reCalculate(int i)
	{
		tree[i] = min(tree[2 * i + 1] + delta[2 * i + 1], tree[2 * i + 2] + delta[2 * i + 2]);
	}

	void propagate(int i)
	{
		delta[2 * i + 1] += delta[i];
		delta[2 * i + 2] += delta[i];
		delta[i] = 0;
	}

	void update(int left, int right, long long val, int i, int l, int r)
	{
		if (r <= left or right <= l)
			return;
		if (left <= l && r <= right)
			return void(delta[i] += val);
		propagate(i);
		int mid = (l + r) / 2;
		update(left, right, val, 2 * i + 1, l, mid);
		update(left, right, val, 2 * i + 2, mid, r);
		reCalculate(i);
	}

	long long query(int left, int right, int i, int l, int r)
	{
		if (r <= left or right <= l)
			return OO;
		if (left <= l && r <= right)
			return tree[i] + delta[i];
		propagate(i);
		int mid = (l + r) / 2;
		long long ls = query(left, right, 2 * i + 1, l, mid);
		long long rs = query(left, right, 2 * i + 2, mid, r);
		reCalculate(i);
		return min(ls, rs);
	}

public:
	void intiialize(int n)
	{
		this->n = n;
		tree.assign(4 * n, 0);
		delta.assign(4 * n, 0);
	}

	void update(int left, int right, long long val)
	{
		update(left, right, val, 0, 0, n);
	}

	long long query(int left, int right)
	{
		return query(left, right, 0, 0, n);
	}
};

int n;
SegmentTree st[2];

bool check()
{
	if (st[0].query(0, 1) != 0)
		return false;
	if (st[0].query(0, n) < 0 or st[1].query(0, n) < 0)
		return false;
	return true;
}

void update(int i, long long v)
{
	int k = i % 2;
	st[k].update(0, i + 1, v);
	st[!k].update(0, i + 1, -v);
}

void testCase()
{
	cin >> n;
	vector<long long> a(n);
	for (long long &ai : a)
		cin >> ai;
	st[0].intiialize(n);
	st[1].intiialize(n);
	long long s = 0;
	for (int i = n - 1, k; i >= 0; i--)
	{
		s = a[i] - s;
		k = i % 2;
		st[k].update(i, i + 1, s);
		st[!k].update(i, i + 1, OO);
	}
	// cout << st[0].query(0, n) << '\n';
	bool possible = check();
	for (int i = 0; !possible && i < n - 1; i++)
	{
		update(i, a[i + 1] - a[i]);
		update(i + 1, a[i] - a[i + 1]);
		possible = check();
		update(i + 1, a[i + 1] - a[i]);
		update(i, a[i] - a[i + 1]);
	}
	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		testCase();
}