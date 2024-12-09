#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N,L,K;
ll A[SIZE],D[SIZE];
ll SUM[SIZE];


ll calc(ll head_index,ll head_loc,ll tail_index){

	ll n_1 = (L-head_loc+1);
	ll first_1 = A[head_index]+(head_loc-1)*D[head_index];
	ll sum_head = (n_1*(2*first_1+(n_1-1)*D[head_index]))/2;

	ll n_2 = (K-(n_1))%L;
	if(n_2 == 0){
		n_2 = L;
	}
	ll first_2 = A[tail_index];
	ll sum_tail = (n_2*(2*first_2+(n_2-1)*D[tail_index]))/2;

	return sum_head+sum_tail;
}


int main(){

	scanf("%lld %lld %lld",&N,&L,&K);

	SUM[0] = 0;

	for(int i = 1; i <= N; i++){

		scanf("%lld %lld",&A[i],&D[i]);

		SUM[i] = (L*(2*A[i]+(L-1)*D[i]))/2;
		SUM[i] += SUM[i-1];
	}

	ll add_index;

	if(K <= L){

		add_index = 0;

	}else{ //K > L

		if((K-L)%L == 0){

			add_index = (K-L)/L;

		}else{

			add_index = (K-L)/L+1;
		}
	}

	//末尾の数列のindexが切り替わる位置を求める
	ll MID;
	ll left = 1,right = L,mid = (left+right)/2;
	ll tmp,tmp_add;

	while(left <= right){

		tmp = L-mid+1;

		if((K-tmp)%L == 0){

			tmp_add = (K-tmp)/L;

		}else{

			tmp_add = (K-tmp)/L+1;
		}

		if(tmp_add == add_index){

			MID = mid;
			left = mid+1;

		}else{

			right = mid-1;
		}
		mid = (left+right)/2;
	}

	ll ans = 0;
	ll tail_index,base_sum;
	ll calc_L,calc_R,mid1,mid2;

	for(ll i = 1; i <= N; i++){

		tail_index = min(i+add_index,N);
		if(tail_index >= i+2){

			base_sum = SUM[tail_index-1]-SUM[i];

		}else{

			base_sum = 0;
		}

		//1-MIDで検索
		if(tail_index == i){

			//最も右側の数列
			ll first = A[i];
			if(L >= K){

				first += (L-K)*D[i];
			}

			tmp = (min(L,K)*(2*(first)+(min(L,K)-1)*D[i]))/2;
			ans = max(ans,base_sum+tmp);

		}else{

			calc_L = 1, calc_R = MID;

			while(calc_L+2 < calc_R){

				mid1 = (2*calc_L+calc_R)/3;
				mid2 = (calc_L+2*calc_R)/3;

				if(calc(i,mid1,tail_index) > calc(i,mid2,tail_index)){

					calc_R = mid2;
				}else{

					calc_L = mid1;
				}
			}

			for(int k = calc_L; k <= calc_R; k++){

				ans = max(ans,base_sum+calc(i,k,tail_index));
			}
		}

		if(MID == L)continue;
		//MID+1-Lで検索

		calc_L = MID+1, calc_R = L;

		tail_index++;
		tail_index = min(tail_index,N);

		if(tail_index >= i+2){

			base_sum = SUM[tail_index-1]-SUM[i];

		}else{

			base_sum = 0;
		}

		while(calc_L+2 < calc_R){

			mid1 = (2*calc_L+calc_R)/3;
			mid2 = (calc_L+2*calc_R)/3;

			if(calc(i,mid1,tail_index) > calc(i,mid2,tail_index)){

				calc_R = mid2;
			}else{

				calc_L = mid1;
			}
		}

		for(int k = calc_L; k <= calc_R; k++){

			ans = max(ans,base_sum+calc(i,k,tail_index));
		}
	}

	printf("%lld\n",ans);

	return 0;
}

