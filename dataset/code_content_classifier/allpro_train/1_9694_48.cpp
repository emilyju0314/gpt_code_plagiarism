#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <iostream>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

int div_row[8] = {-1,-1,-1,0,0,1,1,1},div_col[8] = {-1,0,1,-1,1,-1,0,1},H,W;


int main(){

	int work_row,work_col,max_length;
	char table[10][21];
	string ans;

	set<string> SPELL;

	while(true){
		cin >> H >> W;
		if(H == 0 && W == 0)break;

		SPELL.clear();
		ans = "0";

		for(int i = 0; i < H; i++){
			for(int k = 0; k < W; k++)cin >>table[i][k];
		}

		max_length = 2;

		for(int row = 0; row < H; row++){
			for(int col = 0; col < W; col++){
				for(int a = 0; a < 8; a++){

					string work;
					work += table[row][col];

					work_row = (row + div_row[a]+H)%H;
					work_col = (col + div_col[a]+W)%W;

					while(work_row != row || work_col != col){
						work += table[work_row][work_col];

						if(SPELL.find(work) != SPELL.end()){
							if(work.length() > max_length){
								max_length = work.length();
								ans = work;
							}else if(work.length() == max_length){
								if(work < ans){
									ans = work;
								}
							}
						}else{
							SPELL.insert(work);
						}
						work_row = (work_row + div_row[a]+H)%H;
						work_col = (work_col + div_col[a]+W)%W;
					}
				}
			}
		}

		cout << ans << endl;

	}

	return 0;
}