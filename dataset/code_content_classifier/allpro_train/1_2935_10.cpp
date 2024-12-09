#include <cstdio>
#include <cstring>

#define MAX (1000000)

using namespace std;

typedef long long lint;

int eulerPhi(int n) {
	int ans;
	int x;
	if (n == 0){
		return (0);
	}
 	ans = n;
	for (x = 2; x * x <= n; ++x){
		if (n % x == 0) {
			ans -= ans / x;
			while (n % x == 0){
				n /= x;
			}
		}
	}
	if (n > 1){
		ans -= ans / n;
	}
	return (ans);
}
int main(void)
{
        int n, m;
	int i, j;
	static lint euler[MAX + 1];
	
	for (i = 1; i <= MAX; i++){
		euler[i] = eulerPhi(i);
	}
	
	for (i = 1; i <= MAX; i++){
		euler[i] += euler[i - 1];
	}
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &m);
		printf("%lld\n", euler[m] + 1);
	}
	
	return (0);
}