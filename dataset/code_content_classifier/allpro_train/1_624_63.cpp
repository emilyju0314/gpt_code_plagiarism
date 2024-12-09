#include <iostream>
#include <cstring>

namespace wxy{
	const int N = 105;
	double f[N][10005];
	int a[N],b[N];
	void main(){
		int n;std::cin >> n;
		for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];
		for (int j = 0; j <= 100; j++){
			for (int k = 0; k <= 10000; k++) f[j][k] = -10000;
		}
		f[0][0] = 0;
		double sum = 0;
		for (int i = 1; i <= n; i++) sum += b[i];
		for (int i = 1; i <= n; i++)
			for (int j = i; j >= 1; j--)
				for (int k = 10000; k >= a[i]; k--)
					f[j][k] = std::max(f[j][k],f[j - 1][k - a[i]] + b[i]);
		for (int i = 1; i <= n; i++){
			double ans = 0;
			for (int j = 1; j <= 10000; j++){
				double k = j;
				ans = std::max(ans,std::min(k,(sum + f[i][j]) / 2));
			}
			std::cout << ans << " ";
		}
	}
}signed main(){wxy::main();return 0;}
