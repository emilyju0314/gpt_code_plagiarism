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


vector<int> V[100001];

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	bool* check_GU = new bool[N+1];
	bool* check_KI = new bool[N+1];

	for(int i = 1; i <= N; i++){
		check_GU[i] = false;
		check_KI[i] = false;
	}

	int from,to;
	for(int loop = 0; loop < M; loop++){
		scanf("%d %d",&from,&to);
		V[from].push_back(to);
		V[to].push_back(from);
	}

	bool FLG,GU_FLG = true,KI_FLG = true;

	check_GU[1] = true;
	vector<int> new_GU,new_KI;
	int loop = 0;
	new_GU.push_back(1);

	int current,num_GU = 1,num_KI = 0;

	while(GU_FLG == true && KI_FLG == true){

		if(loop%2 == 0 && GU_FLG == true){
			new_KI.clear();

			FLG = false;

			for(int i = 0; i < new_GU.size(); i++){
				current = new_GU[i];
				for(int k = 0; k < V[current].size(); k++){
					if(check_KI[V[current][k]] == false){
						FLG = true;
						check_KI[V[current][k]] = true;
						new_KI.push_back(V[current][k]);
						num_KI++;
					}
				}
			}

			if(num_KI == N){
				printf("%d\n",loop+1);
				return 0;
			}
			if(!FLG){
				KI_FLG = false;
			}

		}else if(loop%2 == 1 && KI_FLG == true){
			new_GU.clear();

			FLG = false;

			for(int i = 0; i < new_KI.size(); i++){
				current = new_KI[i];
				for(int k = 0; k < V[current].size(); k++){
					if(check_GU[V[current][k]] == false){
						FLG = true;
						check_GU[V[current][k]] = true;
						new_GU.push_back(V[current][k]);
						num_GU++;
					}
				}
			}

			if(num_GU == N){
				printf("%d\n",loop+1);
				return 0;
			}
			if(!FLG){
				GU_FLG = false;
			}
		}
		loop++;
	}

	printf("-1\n");

	return 0;
}