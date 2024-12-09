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



#define NUM 51

struct Info{
	Info(int arg_node_id,int arg_num){
		node_id = arg_node_id;
		num = arg_num;
	}
	bool operator<(const struct Info & arg) const{
		return num > arg.num;
	}

	int node_id,num;
};

int N;
int in_table[NUM],out_table[NUM],calc_out[NUM];
int edge_exist[NUM][NUM];
vector<int> G[NUM];

/*
 * TEST
 * TEST
 * TEST
 * TEST
 * TEST
 * TEST
 * TEST
 * TEST
 * TEST
 */

int main(){

	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++)edge_exist[i][k] = 0;
	}

	int sum = 0,in_sum = 0;
	for(int i = 0; i <= N; i++){
		scanf("%d",&in_table[i]);
		sum += in_table[i];
		in_sum += i*in_table[i];
	}

	if(sum != N){
		printf("NO\n");
		return 0;
	}

	sum = 0;
	int out_sum = 0;
	for(int i = 0; i <= N; i++){
		scanf("%d",&out_table[i]);
		sum += out_table[i];
		out_sum += i*out_table[i];
	}

	if(sum != N){
		printf("NO\n");
		return 0;
	}

	if(in_sum != out_sum){
		printf("NO\n");
		return 0;
	}

	vector<Info> IN_NODE;
	int index = 0;

	for(int i = N; i >= 0; i--){
		for(int k = 0; k < in_table[i]; k++){
			IN_NODE.push_back(Info(index++,i));
		}
	}

	index = 0;

	for(int i = N; i >= 0; i--){
		for(int k = 0; k < out_table[i]; k++){
			calc_out[index++] = i;
		}
	}

	int count;

	for(int i = 0; i < N; i++){
		if(calc_out[i] == 0)continue;

		count = 0;
 		for(int k = 0; k < N; k++){
 			if(IN_NODE[k].num == 0)break;
 			count++;
 			IN_NODE[k].num--;
 			G[i].push_back(IN_NODE[k].node_id);
 			if(count == calc_out[i])break;
		}

 		if(count < calc_out[i]){
 			printf("NO\n");
 			return 0;
 		}

 		sort(IN_NODE.begin(),IN_NODE.end());
	}

	for(int i = 0; i < N; i++){
		for(int k = 0; k < G[i].size(); k++){
			edge_exist[i][G[i][k]] = 1;
		}
	}

	printf("YES\n");

	for(int i = 0; i < N; i++){
		printf("%d",edge_exist[i][0]);
		for(int k = 1; k < N; k++){
			printf(" %d",edge_exist[i][k]);
		}
		printf("\n");
	}

	return 0;
}

