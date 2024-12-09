#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	
	int N, W, H, x_, y_, S, T;
	
	bool map[500][500];
	
	while(true){
		cin >> N;
		if(N == 0){
			break;
		}
		cin >> W >> H;
		for(int i = 0; i < 500; i++){
			for(int j = 0; j < 500; j++){
				map[i][j] = false;
			}
		}
		for(int i = 0; i < N; i++){
			cin >> x_ >> y_;
			map[y_][x_] = true;
		}
		int sx, sy, gx, gy;
		
		cin >> S >> T;
		
		int count, max;
		
		max = 0;
		
		for(int sx = 1; sx + S - 1 <= W; sx++){
			for(int sy = 1; sy + T - 1 <= H; sy++){
				count = 0;
				for(int x = sx; x < sx + S; x++){
					for(int y = sy; y < sy + T; y++){
						if(map[y][x]){
							count++;
						}
					}
				}
				if(count > max){
					max = count;
				}
			}
		}
		printf("%d\n", max);
	}
	
	return 0;
}