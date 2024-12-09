#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll NUM1 = 999979;
ll NUM2 = 999983;

ll gcd(ll a,ll b){
	if(a < b)swap(a,b);

	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}

ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}else{
		ll ret = extgcd(b,(a%b),y,x);
		y -= (a/b)*x;
		return ret;
	}
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    if(extgcd(a,m,x,y) != 1)return 0;
    return (m+x%m)%m;
}

void calc(ll &value1,ll &value2,ll op,ll number){
	switch(op){
	case 1:
		value1 = (value1+number)%NUM1;
		value2 = (value2+number)%NUM2;
		break;
	case 2:
		value1 = (value1-number+NUM1)%NUM1;
		value2 = (value2-number+NUM2)%NUM2;
		break;
	case 3:
		value1 = value1*number%NUM1;
		value2 = value2*number%NUM2;
		break;
	case 4:
		value1 = value1*mod_inverse(number,NUM1)%NUM1;
		value2 = value2*mod_inverse(number,NUM2)%NUM2;
		break;
	}
}

int main(){

	int N;
	scanf("%d",&N);

	ll value1 = 0,value2 = 0,op,number;

	for(int i = 0; i < N; i++){
		scanf("%lld %lld",&op,&number);
		calc(value1,value2,op,number);
	}

	ll X,Y;
	extgcd(NUM1,NUM2,X,Y);

	ll ans = (NUM1*X*value2+NUM2*Y*value1)%(NUM1*NUM2);
	ll check = pow(2,31);

	if(ans >= check){
		ans -= NUM1*NUM2;
	}

	printf("%lld\n",ans);

	return 0;
}

