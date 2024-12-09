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


#define NUM 1001

int capacity[NUM],table[NUM];

int main(){

	int N;
	scanf("%d",&N);

	for(int i = 1; i <= N; i++){
		scanf("%d",&capacity[i]);
		table[i] = 0;
	}

	int Q;
	scanf("%d",&Q);

	int command,apple_id,num;

	for(int loop = 0; loop < Q; loop++){
		scanf("%d %d %d",&command,&apple_id,&num);

		if(command == 1){
			table[apple_id] += num;
			if(table[apple_id] > capacity[apple_id]){
				printf("%d\n",apple_id);
				return 0;
			}
		}else{
			table[apple_id] -= num;
			if(table[apple_id] < 0){
				printf("%d\n",apple_id);
				return 0;
			}
		}

	}

	printf("0\n");

	return 0;
}

