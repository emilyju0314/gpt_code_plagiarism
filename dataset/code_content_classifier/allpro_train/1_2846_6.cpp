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


struct Info{
	int normal,compress;
};


int N,M;
int POW[15];
int min_num[16384];
Info info[14];


void func(){

	for(int i = 0; i < N; i++){
		scanf("%d %d",&info[i].normal,&info[i].compress);
	}

	min_num[0] = 0;
	for(int i = 1; i < POW[N]; i++)min_num[i] = BIG_NUM;

	int ROOM,count,index_table[N];
	int add,compress_size;

	for(int state = 0; state < POW[N]-1; state++){
		if(min_num[state] == BIG_NUM)continue;

		ROOM = M;
		count = 0;

		for(int loop = 0; loop < N; loop++){
			if(state & (1 << loop)){
				ROOM += (info[loop].normal-info[loop].compress);
			}else{
				index_table[count] = loop;
				count++;
			}
		}

		for(int i = 0; i < POW[count]; i++){
			compress_size = 0;
			add = 0;
			for(int loop = 0; loop < count; loop++){
				if(i & (1 << loop)){
					compress_size += info[index_table[loop]].compress;
					add += POW[index_table[loop]];
				}
				if(compress_size > ROOM)continue;
				min_num[state+add] = min(min_num[state+add],min_num[state]+1);
			}
		}
	}

	if(min_num[POW[N]-1] == BIG_NUM){
		printf("Impossible\n");
	}else{
		printf("%d\n",min_num[POW[N]-1]);
	}
}


int main(){

	for(int i = 0; i < 15; i++)POW[i] = pow(2,i);

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		func();
	}

	return 0;
}