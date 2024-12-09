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

#define NUM 100000

struct Info{
	void set(int arg_start,int arg_end){
		start = arg_start;
		end = arg_end;
	}
	int start,end;
};

int table1_start[100002],table1_end[100002],table2[100002];
Info info[200000];


int main(){

	int N;
	scanf("%d",&N);

	for(int i = 0; i <= 100001; i++){
		table1_start[i] = 0;
		table1_end[i] = 0;
		table2[i] = 0;
	}

	int a,b,maximum = 0;

	for(int loop = 0; loop < N; loop++){
		scanf("%d %d",&a,&b);
		maximum = max(maximum,b);
		info[loop].set(a,b);
		table1_start[a]++;
		table1_end[b]++;
		table2[a]++;
		table2[b]--;
	}

	for(int i = 1; i <= maximum; i++){
		table1_start[i] += table1_start[i-1];
		table1_end[i] += table1_end[i-1];
	}

	int max_1 = 0;
	int end_after_i_start_num,start_after_i_end_num;

	for(int i = 0; i < N; i++){
		end_after_i_start_num = table1_end[maximum]-table1_end[info[i].start];
		start_after_i_end_num = table1_start[maximum]-table1_start[info[i].end-1];
		max_1 = max(max_1,end_after_i_start_num-start_after_i_end_num);
	}

	int max_2 = 0;
	for(int i = 1; i <= maximum; i++){
		table2[i] += table2[i-1];
		max_2 = max(max_2,table2[i]);
	}

	printf("%d %d\n",max_1,max_2);

	return 0;
}