#include <stdio.h>

void put(int,int,int,int);
void tansaku(int,int);

const int nashi=-1;
const int tootta=10;

int field[102][102];
int main(int argc,char* argv[]){
	while(1){
		int x_size,y_size;
		int sx,sy;
		int gx,gy;
		int n;
		scanf("%d %d",&x_size,&y_size);
		if(x_size==0)
			return 0;

		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&gx,&gy);
		scanf("%d",&n);

		for(int i=0;i<y_size+2;i++)
			for(int j=0;j<x_size+2;j++)
				field[i][j]=nashi;

		for(int i=0;i<n;i++){
			int c,d,x,y;
			scanf("%d %d %d %d",&c,&d,&x,&y);
			put(c,d,x,y);
		}

		tansaku(sx,sy);
		if(field[gy][gx]==tootta)
			printf("OK\n");
		else
			printf("NG\n");
	}
}

void put(int c,int d,int x,int y){
	const int size[2][2]={{4,2},{2,4}};
	for(int i=0;i<size[d][1];i++){
		for(int j=0;j<size[d][0];j++){
			field[y+i][x+j]=c;
		}
	}
}

void tansaku(int sx,int sy){
	int c=field[sy][sx];
	field[sy][sx]=tootta;
	if(field[sy][sx-1]==c)
		tansaku(sx-1,sy);
	if(field[sy][sx+1]==c)
		tansaku(sx+1,sy);
	if(field[sy-1][sx]==c)
		tansaku(sx,sy-1);
	if(field[sy+1][sx]==c)
		tansaku(sx,sy+1);
}