#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;

using namespace std;

struct Info{
	int J,O,I;
};

int main(){

	int H,W;
	scanf("%d %d",&H,&W);

	char buf[W+1];
	Info** info = (Info**)malloc(sizeof(Info*)*(H+1));
	for(int i = 0; i <= H; i++){
		info[i] = (Info*)malloc(sizeof(Info)*(W+1));
	}

	for(int i = 0; i <= H; i++){
		for(int k = 0; k <= W; k++){
			info[i][k].J = 0;
			info[i][k].O = 0;
			info[i][k].I = 0;
		}
	}

	int Q;
	scanf("%d",&Q);

	for(int i = 1; i <= H; i++){
		scanf("%s",buf);
		for(int k = 0; k < W; k++){
			switch(buf[k]){
			case 'J':
				info[i][k+1].J++;
				break;
			case 'O':
				info[i][k+1].O++;
				break;
			case 'I':
				info[i][k+1].I++;
				break;
			}

			info[i][k+1].J += info[i][k].J;
			info[i][k+1].O += info[i][k].O;
			info[i][k+1].I += info[i][k].I;
		}
	}

	int a,b,c,d,J_num,O_num,I_num;

	for(int loop = 0; loop < Q; loop++){
		scanf("%d %d %d %d",&a,&b,&c,&d);

		J_num = 0,O_num =0,I_num = 0;
		for(int i = a; i <= c; i++){
			J_num += info[i][d].J - info[i][b-1].J;
			O_num += info[i][d].O - info[i][b-1].O;
			I_num += info[i][d].I - info[i][b-1].I;
		}
		printf("%d %d %d\n",J_num,O_num,I_num);

	}

	return 0;
}