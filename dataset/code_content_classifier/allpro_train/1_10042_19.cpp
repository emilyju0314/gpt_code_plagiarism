#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 2500005

ll M,N,m_0,m_d,n_0,n_d;
ll to_carrot[NUM],to_kiwi[NUM];
ll ruiseki_carrot[NUM],ruiseki_kiwi[NUM];

ll calc(int carrot_index,int kiwi_index){
	return (M-carrot_index)*(N-kiwi_index)+ruiseki_carrot[carrot_index]+ruiseki_kiwi[kiwi_index];
}

int main(){

	scanf("%lld %lld %lld %lld %lld %lld",&M,&N,&m_0,&m_d,&n_0,&n_d);

	to_carrot[0] = m_0;
	for(int i = 1; i < M; i++){
		to_carrot[i] = (to_carrot[i-1]*58+m_d)%(N+1);
	}

	to_kiwi[0] = n_0;
	for(int i = 1; i < N; i++){
		to_kiwi[i] = (to_kiwi[i-1]*58+n_d)%(M+1);
	}

	sort(to_carrot,to_carrot+M);
	sort(to_kiwi,to_kiwi+N);

	ruiseki_carrot[0] = 0;
	for(int i = 1; i <= M; i++){
		ruiseki_carrot[i] = to_carrot[i-1];
		ruiseki_carrot[i] += ruiseki_carrot[i-1];
	}

	ruiseki_kiwi[0] = 0;
	for(int i = 1; i <= N; i++){
		ruiseki_kiwi[i] = to_kiwi[i-1];
		ruiseki_kiwi[i] += ruiseki_kiwi[i-1];
	}

	int kiwi_index = N;

	ll ans = ruiseki_kiwi[kiwi_index];

	for(int carrot_index = 1; carrot_index <= M; carrot_index++){
		while(kiwi_index > 0 && calc(carrot_index,kiwi_index-1) <= calc(carrot_index,kiwi_index)){
			kiwi_index--;
		}
		ans = min(ans,calc(carrot_index,kiwi_index));
	}

	printf("%lld\n",ans);

	return 0;
}

