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
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

enum Type{
	Call,
	Called_or_Lonely,
};

int N,memo[5001][2];

vector<int> V[5001];

int recursive(int node_id,Type type){

	if(memo[node_id][type] != -1)return memo[node_id][type];

	int ret = 0,tmp,sum;

	switch(type){
	case Call:
		sum = 0;
		for(int i = 0; i < V[node_id].size(); i++){
			sum += max(recursive(V[node_id][i],Call),recursive(V[node_id][i],Called_or_Lonely));
		}
		for(int i = 0; i < V[node_id].size(); i++){
			ret = max(ret,sum-max(memo[V[node_id][i]][Call],memo[V[node_id][i]][Called_or_Lonely])+recursive(V[node_id][i],Called_or_Lonely)+1);
		}
		break;
	case Called_or_Lonely:
		for(int i = 0; i < V[node_id].size(); i++){
			ret += max(recursive(V[node_id][i],Call),recursive(V[node_id][i],Called_or_Lonely));
		}
		break;
	}

	return memo[node_id][type] = ret;
}

int func(){

	return max(recursive(0,Call),recursive(0,Called_or_Lonely));
}


int main(void){

	scanf("%d",&N);
	int tmp;

    for(int day = 1;day <= N; day++){

        scanf("%d",&tmp);
        V[tmp].push_back(day);
        for(int i = 0; i <= day; i++){
        	for(int k = 0; k < 3; k++)memo[i][k] = -1;
        }

        printf("%d\n",func());
    }
    return 0;
}