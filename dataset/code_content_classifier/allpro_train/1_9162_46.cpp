#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

string T;
unordered_map < long long , bool > have;

namespace H2 {

	long long mod = 1000000009LL;

	long long power(long long a, long long b)
	{
		long long ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret * a) % mod;
			a = (a * a) % mod;
			b /= 2;
		}
		return ret;
	}


	long long inv(long long x)
	{
		return power(x, mod - 2);
	}

	long long base = 10000019;
	long long val[100001];
	long long invPow[100001];

	long long getHash(int start, int len)
	{
		long long v = val[start + len] - val[start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}



	void prepare()
	{
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= 100000; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < T.length(); i++)
		{
			val[i+1] = (val[i] + (long long)T[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}

}


namespace H1 {

	long long mod = 1000000007LL;

	long long power(long long a, long long b)
	{
		long long ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret * a) % mod;
			a = (a * a) % mod;
			b /= 2;
		}
		return ret;
	}


	long long inv(long long x)
	{
		return power(x, mod - 2);
	}

	long long base = 22222223;
	long long val[100001];
	long long invPow[100001];

	long long getHash(int start, int len)
	{
		long long v = val[start + len] - val[start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}



	void prepare()
	{
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= 100000; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < T.length(); i++)
		{
			val[i+1] = (val[i] + (long long)T[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}

}

int calc(int len)
{
	int cnt = 0;
	have.clear();
	for(int offset = 0; offset + len <= T.length(); offset ++)
	{
		long long s = H1::getHash(offset, len) + H2::getHash(offset, len) * 1000000010;
		if(have.count(s)) continue;
		have[s] = true;
		cnt ++;
	}
	return cnt;
}

int MAIN()
{
	
	cin >> T;
	
	H1::prepare();
	H2::prepare();

	long long L = 1, R = T.length();
	while(R - L > 3)
	{
		long long M1 = (2*L + R) / 3;
		long long M2 = (2*R + L) / 3;
		if(calc(M1) < calc(M2))
			L = M1;
		else
			R = M2;
	}
	int ans = 0;
	for(int i = L; i <= R; i++)
		ans = max(ans, calc(i));
	cout << ans << endl;
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
