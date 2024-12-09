#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
LL q, a, b, pf;
int main(){
	scanf("%lld", &q);
	while(q--){
		scanf("%lld%lld", &a, &b);
		pf = sqrt(a * b);
		if(a == b) printf("%lld\n",(a - 1) * 2);
		else if(pf * (pf + 1) < a * b) printf("%lld\n", 2 * pf - 1);
		else if(pf * pf < a * b) printf("%lld\n", 2 * pf - 2);
		else if(pf * (pf - 1) < a * b) printf("%lld\n", 2 * pf - 3);
	}
}