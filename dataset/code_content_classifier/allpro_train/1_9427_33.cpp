#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int team, score;
	
	int p[1000], rank[1000];
	
	for(int i = 0; i < 1000; i++){
		p[i] = 0;
	}
	
	scanf("%d,%d", &team, &score);
	
	while(team != 0 || score != 0){
		p[team] = score;
		scanf("%d,%d", &team, &score);
	}
	
	bool checker;
	int ranking;
	
	ranking = 1;
	
	for(int i = 30; i >= 0; i--){
		checker = false;
		for(int j = 0; j < 1000; j++){
			if(p[j] == i){
				checker = true;
				rank[j] = ranking;
			}
		}
		if(checker){
			ranking++;
		}
	}
	
	while(true){
		int num;
		cin >> num;
		if(cin.eof()){
			break;
		}
		printf("%d\n", rank[num]);
	}
	
	return 0;
}