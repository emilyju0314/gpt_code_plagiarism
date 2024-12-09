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



int main(){

	int N;
	vector<int> V;

	scanf("%d",&N);

	int num_0 = 0,num_1 = 0;

	int tmp;
	for(int loop = 0; loop < N; loop++){
		scanf("%d",&tmp);
		if(tmp == 0){
			num_0++;
		}else if(tmp == 1){
			num_1++;
		}else{
			V.push_back(tmp);
		}
	}

	sort(V.begin(),V.end());

	int size = (int)V.size();

	if(num_0%2 == 0){
		if(size >= 2 && V[size-2] == 2 && V[size-1] == 3){
			swap(V[size-2],V[size-1]);
		}

		for(int i = 0; i < size; i++){
			printf("%d\n",V[i]);
		}
		for(int i = 0; i < num_0; i++){
			printf("0\n");
		}
		for(int i = 0; i < num_1; i++){
			printf("1\n");
		}
	}else{

		if(num_1 > 0){

			if(size >= 2 && V[size-2] == 2 && V[size-1] == 3){
				swap(V[size-2],V[size-1]);
			}
			for(int i = 0; i < size; i++){
				printf("%d\n",V[i]);
			}
			for(int i = 0; i < num_0-1; i++){
				printf("0\n");
			}
			printf("1\n0\n");
			for(int i = 0; i < num_1-1; i++){
				printf("1\n");
			}
		}else{

			if(size > 0){
				tmp = V[0];
				V.erase(V.begin()+0);

				size--;

				if(size >= 2 && V[size-2] == 2 && V[size-1] == 3){
					swap(V[size-2],V[size-1]);
				}

				for(int i = 0; i < size; i++){
					printf("%d\n",V[i]);
				}

				for(int i = 0; i < num_0-1; i++){
					printf("0\n");
				}
				printf("%d\n0\n",tmp);

			}else{

				for(int i = 0; i < num_0; i++){
					printf("0\n");
				}
			}
		}
	}

	return 0;
}

