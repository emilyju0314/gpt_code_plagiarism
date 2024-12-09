#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll *min_data,*max_data,*add_data;
char buf[300001];
int N = 1;

void init(ll first_N){
	while(N < first_N)N *= 2;
}

void add(int left,int right,ll value,int node_id,int node_left,int node_right){

	if(right < node_left || left > node_right){
		//範囲外ならreturn
		return;
	}
	else if(left <= node_left && right >= node_right){ //このノードのカバーしている区間が、更新区間の部分区間である場合

		add_data[node_id] += value; //一様に加える値を加算

		while(node_id != 0){

			node_id = (node_id-1)/2; //下から上に向かって、最小値および最大値更新
			min_data[node_id] = min(min_data[2*node_id+1]+add_data[2*node_id+1],min_data[2*node_id+2]+add_data[2*node_id+2]);
			max_data[node_id] = max(max_data[2*node_id+1]+add_data[2*node_id+1],max_data[2*node_id+2]+add_data[2*node_id+2]);
		}
	}else{

		add(left,right,value,2*node_id+1,node_left,(node_left+node_right)/2);
		add(left,right,value,2*node_id+2,(node_left+node_right)/2+1,node_right);
	}
}

ll getMin(int left,int right,int node_id,int node_left,int node_right){
	if(right < node_left || left > node_right)return BIG_NUM;
	else if(left <= node_left && right >= node_right){
		return min_data[node_id]+add_data[node_id];

	}else{

		ll  left_min  = getMin(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		ll  right_min = getMin(left,right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return min(left_min,right_min)+add_data[node_id];
	}
}

ll getMax(int left,int right,int node_id,int node_left,int node_right){
	if(right < node_left || left > node_right)return -BIG_NUM;
	else if(left <= node_left && right >= node_right){
		return max_data[node_id]+add_data[node_id];

	}else{

		ll  left_max  = getMax(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		ll  right_max = getMax(left,right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return max(left_max,right_max)+add_data[node_id];
	}
}

int main(){

	int first_N,Q;
	scanf("%d %d",&first_N,&Q);

	init(first_N);

	min_data = new ll[2*N-1];
	max_data = new ll[2*N-1];
	add_data = new ll[2*N-1];

	for(ll i = 0; i <= 2*N-2; i++){
		min_data[i] = 0;
		max_data[i] = 0;
		add_data[i] = 0;
	}

	scanf("%s",buf);

	set<int> CLOSE;

	for(int i = 0; i < first_N; i++){
		if(buf[i] == '('){
			add(i,N-1,1,0,0,N-1);
		}else{
			CLOSE.insert(i);
			add(i,N-1,-1,0,0,N-1);
		}
	}

	int loc,calc_loc;
	int left,right,m;

	for(int i = 0; i < Q; i++){
		scanf("%d",&loc);
		loc--;

		if(buf[loc] == '('){

			buf[loc] = ')';
			add(loc,N-1,-2,0,0,N-1);
			CLOSE.insert(loc);

			calc_loc = *begin(CLOSE);
			CLOSE.erase(begin(CLOSE));

			add(calc_loc,N-1,2,0,0,N-1);
			buf[calc_loc] = '(';
			printf("%d\n",calc_loc+1);

		}else{ //buf[loc] == ')'

			CLOSE.erase(loc);
			buf[loc] = '(';
			add(loc,N-1,2,0,0,N-1);

			left = 0,right = first_N-1, m = (left+right)/2;

			while(left <= right){
				if(getMin(m,N-1,0,0,N-1) >= 2){
					calc_loc = m;
					right = m-1;
				}else{
					left = m+1;
				}
				m = (left+right)/2;
			}

			while(buf[calc_loc] != '(')calc_loc++;

			buf[calc_loc] = ')';
			add(calc_loc,N-1,-2,0,0,N-1);

			printf("%d\n",calc_loc+1);
			CLOSE.insert(calc_loc);
		}
	}

	return 0;
}

