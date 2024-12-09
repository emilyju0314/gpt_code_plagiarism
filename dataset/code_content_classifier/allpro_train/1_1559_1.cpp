#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005


enum Type{
	COUNT,
	WEIGHT,
};

struct Info{
	int index;
	ll weight;
};

int N;
ll C,BIT[NUM][2];
Info info[NUM];

void add(ll loc,ll value,Type type, ll maximum){

	BIT[loc][type] += value;

	loc += loc & -loc;

	while(loc <= maximum){

		BIT[loc][type] += value;
		loc += loc & -loc;
	}
}

ll getSum(ll loc,Type type){

	ll sum = BIT[loc][type];

	loc -= loc & -loc;

	while(loc > 0){
		sum += BIT[loc][type];
		loc -= loc & -loc;
	}
	return sum;
}

ll calc(ll left,ll right,Type type){
	return getSum(right,type)-getSum(left-1,type);
}

ll query(int node_id,int node_left,int node_right){

	if(node_left >= N || node_left > node_right)return 0;
	if(node_left == node_right)return 0;

	ll ret = 0;
	ret += query(2*node_id+1,node_left,(node_left+node_right)/2);
	ret += query(2*node_id+2,(node_left+node_right)/2+1,min(node_right,N-1));

	vector<Info> L,R;

	for(int i = node_left; i <= (node_left+node_right)/2; i++){

		L.push_back(info[i]);
	}

	for(int i = (node_left+node_right)/2+1; i <= node_right; i++){

		R.push_back(info[i]);
	}

	for(int i = 0; i < L.size(); i++){

		add(L[i].weight,1,COUNT,NUM-1);
		add(L[i].weight,L[i].weight,WEIGHT,NUM-1);
	}

	int L_index = 0,R_index = 0;

	for(int i = 0; i < L.size()+R.size(); i++){

		if((R_index == R.size()) || (L_index < L.size() && L[L_index].index < R[R_index].index)){

			add(L[L_index].weight,-1,COUNT,NUM-1);
			add(L[L_index].weight,-L[L_index].weight,WEIGHT,NUM-1);
			info[node_left+i].index = L[L_index].index;
			info[node_left+i].weight = L[L_index].weight;
			L_index++;

		}else{

			if(L_index < L.size()){

				ret += calc(R[R_index].weight,NUM-1,COUNT)*C*R[R_index].weight+calc(R[R_index].weight,NUM-1,WEIGHT);
				ret += calc(1,R[R_index].weight-1,WEIGHT)*C+calc(1,R[R_index].weight-1,COUNT)*R[R_index].weight;
			}

			info[node_left+i].index = R[R_index].index;
			info[node_left+i].weight = R[R_index].weight;
			R_index++;
		}
	}

	return ret;
}

int main(){

	scanf("%d %lld",&N,&C);

	for(int i = 0; i < N; i++){

		scanf("%d %lld",&info[i].index,&info[i].weight);
		info[i].index--;
	}

	for(int i = 0; i <= NUM-1; i++){
		BIT[i][COUNT] = 0;
		BIT[i][WEIGHT] = 0;
	}

	printf("%lld\n",query(0,0,N-1));

	return 0;
}

