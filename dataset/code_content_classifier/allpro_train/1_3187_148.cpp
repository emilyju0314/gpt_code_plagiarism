#include<stdio.h>

char map[16][16];
int ans;

void func(int x,int y){
	map[x][y] = 0;
	if(map[x][y+1] == '1' && y+1<13)
		func(x,y+1);
	if(map[x][y-1] == '1' && y-1>-1)
		func(x,y-1);
	if(map[x+1][y] == '1' && x+1<13)
		func(x+1,y);
	if(map[x-1][y] == '1' && x-1>-1)
		func(x-1,y);
	
}

int main(void){
	while(scanf("%s",&map[0])!=EOF){
		int i,j;
		for(i = 1; i < 12; i++){
			scanf("%s",&map[i]);
		}
		
		for(i = 0; i < 12; i++){
			for(j = 0; j < 12; j++){
				if(map[i][j] == '1'){
					ans++;
					func(i,j);
				}
			}
		}
		
		printf("%d\n",ans);
		for(i = 0; i < 12; i++){
			for(j = 0; j < 12; j++){
				map[i][j] = 0;
			}
		}
		ans = 0;
	}
	return 0;
}