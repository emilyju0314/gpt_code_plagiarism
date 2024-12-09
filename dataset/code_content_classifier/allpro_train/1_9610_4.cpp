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

int N,M;
char name[30][21];

int check[20];

int boss[20],height[20];
int POW[31];

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	if(boss_x == boss_y)return;

	if(height[x] > height[y]){

		boss[boss_y] = boss_x;

	}else if(height[x] < height[y]){

		boss[boss_x] = boss_y;

	}else{ //height[x] == height[y]

		boss[boss_y] = boss_x;
		height[x]++;
	}
}

void init(){
	for(int i = 0; i < M; i++){
		boss[i] = i;
		height[i] = 0;
	}
}

bool strCmp(char* base, char* comp){
	int length1,length2;
	for(length1=0;base[length1] != '\0';length1++);
	for(length2=0;comp[length2] != '\0';length2++);
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

int data_set = 0;

void func(){

	if(data_set != 0){
		printf("\n");
	}
	data_set++;

	for(int i = 0; i < N; i++){
		scanf("%s",name[i]);
	}

	for(int i = 0; i < M; i++)check[i] = 0;

	char buf[21];
	int num;

	for(int i = 0; i < M; i++){
		scanf("%d",&num);
		for(int k = 0; k < num; k++){
			scanf("%s",buf);
			for(int p = 0; p < N; p++){
				if(strCmp(name[p],buf)){
					check[i] += POW[p];
					break;
				}
			}
		}
	}

	bool FLG;
	int S;

	for(int a = 0; a < N; a++){
		FLG = true;
		S = POW[a];

		for(int i = 0; i < M; i++){
			if((check[i] & S) == 0){
				FLG = false;
				break;
			}
		}

		if(FLG){
			printf("1\n");
			printf("%s\n",name[a]);
			return;
		}
	}

	if(N == 1){
		printf("Impossible\n");
		return;
	}

	int count;

	for(int a = 0; a < N-1; a++){
		for(int b = a+1; b < N; b++){
			S = POW[a]+POW[b];
			init();

			for(int i = 0; i < M-1; i++){
				for(int k = i+1; k < M; k++){
					if(check[i]&check[k]&S){
						unite(i,k);
					}
				}
			}

			count = 0;
			for(int i = 0; i < M; i++){
				if(get_boss(i) == i)count++;
			}

			if(count == 1){
				printf("2\n");
				printf("%s\n",name[a]);
				printf("%s\n",name[b]);
				return;
			}
		}
	}

	if(N == 2){
		printf("Impossible\n");
		return;
	}


	for(int a = 0; a < N-2; a++){
		for(int b = a+1; b < N-1; b++){
			for(int c = b+1; c < N; c++){
				S = POW[a]+POW[b]+POW[c];
				init();

				for(int i = 0; i < M-1; i++){
					for(int k = i+1; k < M; k++){
						if(check[i]&check[k]&S){
							unite(i,k);
						}
					}
				}

				count = 0;
				for(int i = 0; i < M; i++){
					if(get_boss(i) == i)count++;
				}

				if(count == 1){

					printf("3\n");
					printf("%s\n",name[a]);
					printf("%s\n",name[b]);
					printf("%s\n",name[c]);
					return;

				}
			}
		}
	}

	if(N == 3){
		printf("Impossible\n");
		return;
	}

	for(int a = 0; a < N-3; a++){
		for(int b = a+1; b < N-2; b++){
			for(int c = b+1; c < N-1; c++){
				for(int d = c+1; d < N; d++){
					S = POW[a]+POW[b]+POW[c]+POW[d];
					init();

					for(int i = 0; i < M-1; i++){
						for(int k = i+1; k < M; k++){
							if(check[i]&check[k]&S){
								unite(i,k);
							}
						}
					}

					count = 0;
					for(int i = 0; i < M; i++){
						if(get_boss(i) == i)count++;
					}

					if(count == 1){
						printf("4\n");
						printf("%s\n",name[a]);
						printf("%s\n",name[b]);
						printf("%s\n",name[c]);
						printf("%s\n",name[d]);
						return;
					}
				}
			}
		}
	}

	if(N == 4){
		printf("Impossible\n");
		return;
	}

	for(int a = 0; a < N-4; a++){
		for(int b = a+1; b < N-3; b++){
			for(int c = b+1; c < N-2; c++){
				for(int d = c+1; d < N-1; d++){
					for(int e = d+1; e < N; e++){
						S = POW[a]+POW[b]+POW[c]+POW[d]+POW[e];
						init();

						for(int i = 0; i < M-1; i++){
							for(int k = i+1; k < M; k++){
								if(check[i]&check[k]&S){
									unite(i,k);
								}
							}
						}

						count = 0;
						for(int i = 0; i < M; i++){
							if(get_boss(i) == i)count++;
						}

						if(count == 1){
							printf("5\n");
							printf("%s\n",name[a]);
							printf("%s\n",name[b]);
							printf("%s\n",name[c]);
							printf("%s\n",name[d]);
							printf("%s\n",name[e]);
							return;
						}
					}
				}
			}
		}
	}

	printf("Impossible\n");
}

int main(){

	for(int i = 0; i < 31; i++)POW[i] = pow(2,i);

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		func();
	}

	return 0;
}