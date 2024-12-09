#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define MAX_DIGIT 20
#define SIZE 100005

struct Node{

	int child[2];
	ll count;
};

ll N,K;
int root = 0,num_nodes;
int A[SIZE],POW[MAX_DIGIT+1];
int is_ONE[SIZE][MAX_DIGIT+1],MID[MAX_DIGIT+1];
Node nodes[SIZE*(MAX_DIGIT+1)];

void add(int index){

	int loc = root;

	for(int i = MAX_DIGIT; i >= 0; i--){

		int digit = is_ONE[index][i];

		if(nodes[loc].child[digit] == -1){

			nodes[loc].child[digit] = num_nodes++;
		}
		loc = nodes[loc].child[digit];
		nodes[loc].count++;
	}
}

void init(){

	for(int i = 0; i <= num_nodes; i++){

		nodes[i].child[0] = -1;
		nodes[i].child[1] = -1;
		nodes[i].count = 0;
	}

	num_nodes = 1;
}

ll calc(int index){

	int loc = root;
	ll ret = 0;

	for(int i = MAX_DIGIT; i >= 0; i--){
		int digit = is_ONE[index][i];
		int rev_digit = 1-digit;

		if(MID[i] == 0){

			if(nodes[loc].child[digit] == -1){

				return ret;
			}
			loc = nodes[loc].child[digit];

		}else{ //MID[i] == 1

			if(nodes[loc].child[digit] != -1){

				ret += nodes[nodes[loc].child[digit]].count;
			}
			if(nodes[loc].child[rev_digit] == -1){

				return ret;
			}
			loc = nodes[loc].child[rev_digit];
		}
	}

	ret += nodes[loc].count;
	return ret;
}

int main(){

	POW[0] = 1;
	for(int i = 1; i <= MAX_DIGIT; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%lld %lld",&N,&K);

	num_nodes = SIZE*(MAX_DIGIT+1);

	K = (N*(N+1))/2-K+1;

	A[0] = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d",&A[i]);
		A[i] = A[i]^A[i-1];
	}

	for(int i = 0; i <= N; i++){
		for(int loop = 0; loop < MAX_DIGIT; loop++){
			if(A[i] & POW[loop]){

				is_ONE[i][loop] = 1;

			}else{

				is_ONE[i][loop] = 0;
			}
		}
	}

	int left = 0,right = 2*1024*1024-1,mid = (left+right/2);
	ll ans,tmp;

	while(left <= right){

		for(int loop = 0; loop < MAX_DIGIT; loop++){
			if(mid & POW[loop]){

				MID[loop] = 1;

			}else{

				MID[loop] = 0;
			}
		}

		init();

		tmp = 0;
		for(int i = N; i >= 0; i--){

			tmp += calc(i);
			add(i);
		}

		if(tmp >= K){

			ans = mid;
			right = mid-1;

		}else{

			left = mid+1;
		}

		mid = (left+right)/2;
	}

	printf("%lld\n",ans);

	return 0;
}

