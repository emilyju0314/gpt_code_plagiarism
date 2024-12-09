#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

struct Info{
	Info(int arg_state,int arg_count){
		state = arg_state;
		count = arg_count;
	}
	int state,count;
};

int main(){

	int POW[17] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
	int N,M,K,limit;

	scanf("%d %d %d",&N,&M,&K);

	limit = POW[M];

	int* min_Count = new int[limit];

	for(int i = 0; i < limit; i++){
		min_Count[i] = BIG_NUM;
	}

	bool isDark[N];
	int  dark_Index[M],reverse_dark_Index[N];

	for(int i = 0; i < N; i++)isDark[i] = false;

	vector<int> V[N];

	int tmp;

	for(int i = 0; i < M;i++){
		scanf("%d",&tmp);
		tmp--;
		isDark[tmp] = true;
		dark_Index[i] = tmp;
		reverse_dark_Index[tmp] = i;
	}

	for(int i = 0; i < N; i++){
		for(int p = 0; p < K; p++){
			scanf("%d",&tmp);
			tmp--;
			V[i].push_back(tmp);
		}
	}

	queue<Info> Q;
	Q.push(Info(limit-1,0));
	min_Count[limit-1] = 0;

	int ans,state,next_state,room,next_room,next[M];

	while(!Q.empty()){

		if(Q.front().state == 0){
			ans = Q.front().count;
			break;
		}else if(Q.front().count > min_Count[Q.front().state]){
			Q.pop();
		}else{

			state = Q.front().state;

			for(int instruction = 0; instruction < K; instruction++){

				for(int a = 0; a < M; a++)next[a] = 0;

				for(int a = 0; a < M; a++){

					if(state & (1 << a)){
						room = dark_Index[a];
						next_room = V[room][instruction];
						if(isDark[next_room] == false){
							//Do nothing
						}else{
							next[reverse_dark_Index[next_room]] = 1;
						}
					}
				}

				next_state = 0;
				for(int i = 0; i < M; i++)next_state += POW[i]*next[i];

				if(min_Count[next_state] > Q.front().count+1){
					min_Count[next_state] = Q.front().count+1;
					Q.push(Info(next_state,Q.front().count+1));
				}
			}

			Q.pop();
		}
	}

	printf("%d\n",ans);

	return 0;
}