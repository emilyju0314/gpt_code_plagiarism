#include <cstdio>
#include <vector>
#define MOD 1000000007
typedef long long ll;
struct Matrix
{
	std::vector<std::vector<int> > arr;
	Matrix()
	{
		arr.resize(3, std::vector<int>(3, 0));
	}
	inline std::vector<int> &operator [](const int &x)
	{
		return arr[x];
	}
	inline const std::vector<int> &operator [](const int &x) const
	{
		return arr[x];
	}
	inline Matrix operator *(const Matrix &a) const
	{
		Matrix res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
					res[i][k] = (res[i][k] + (ll)arr[i][j] * a[j][k]) % MOD;
			}
		}
		return res;
	}
} ans, trans, sing;
int arr[100005];
int main()
{
	// freopen("AGC013-E.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", arr + i);
	arr[++m] = n;
	ans[0][0] = 1;
	trans.arr = {{1, 2, 1}, {0, 1, 1}, {1, 2, 2}};
	sing.arr = {{1, 2, 1}, {0, 1, 1}, {0, 0, 1}};
	int cur = 0;
	for (int i = 0; i <= m; i++)
	{
		int x = arr[i] - cur;
		auto tmp = trans;
		while (x)
		{
			if (x & 1)
				ans = ans * tmp;
			tmp = tmp * tmp;
			x >>= 1;
		}
		if (i == m)
			break;
		ans = ans * sing;
		cur = arr[i] + 1;
	}
	printf("%d\n", ans[0][2]);
	return 0;
}
