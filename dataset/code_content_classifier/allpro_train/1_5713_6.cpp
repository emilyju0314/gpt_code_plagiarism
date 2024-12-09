#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum Type{
	YOKO,
	TATE,
};

int H,W,change_limit,base_num;
int table[10][10];

bool FLG;

void recursive(Type type,int changed_count,int base_row,int base_col){

	if(FLG)return;

	if(type == YOKO){

		//その行に、超過シーケンスがあるかどうか調べる
		//行
		int left = -1,right,tmp;
		queue<int> START;

		START.push(0);

		int col,start;

		while(!START.empty()){
			start = START.front();
			START.pop();
			tmp = 0;
			for(col = start; col < W;){
				tmp += table[base_row][col];

				if(tmp < 0){ //start～colまでは、超過シーケンスなし
					if(col <= W-2){
						START.push(col+1);
					}
					break;
				}else if(tmp <= base_num){
					col++;
				}else if(tmp > base_num){

					while(col+1 <= W-1 && tmp+table[base_row][col+1] > base_num){
						col++;
						tmp += table[base_row][col];
					}
					left = start,right = col;
					break;
				}
			}
			if(left != -1)break;
		}

		//なければ次の行へ
		if(left == -1){
			if(base_row == H-1){

				recursive(TATE,changed_count,base_row,0);

			}else{

				recursive(YOKO,changed_count,base_row+1,base_col);

			}

		}else{ //あれば、少なくとも、その区間の1つを変更

			if(changed_count == change_limit)return;

			for(int i = left; i <= right; i++){
				if(table[base_row][i] <= 0)continue;
				table[base_row][i] *= -1;
				recursive(YOKO,changed_count+1,base_row,base_col);
				table[base_row][i] *= -1;
			}
		}

	}else{ //type == TATE

		//その列に、超過シーケンスがあるかどうか調べる
		int top = -1,under,tmp;
		queue<int> START;

		START.push(0);

		int row,start;

		while(!START.empty()){
			start = START.front();
			START.pop();
			tmp = 0;
			for(row = start; row < H;){
				tmp += table[row][base_col];

				if(tmp < 0){ //start～rowまでは、超過シーケンスなし
					if(row <= H-2){
						START.push(row+1);
					}
					break;
				}else if(tmp <= base_num){
					row++;
				}else if(tmp > base_num){

					while(row+1 <= H-1 && tmp+table[row+1][base_col] > base_num){
						row++;
						tmp += table[row][base_col];
					}
					top = start,under = row;
					break;
				}
			}
			if(top != -1)break;
		}

		//なければ次の列へ
		if(top == -1){
			if(base_col == W-1){

				/*for(int row = 0; row < H; row++){
					for(int col = 0; col < W; col++){
						printf("%d ",table[row][col]);
					}
					printf("\n");
				}*/

				FLG = true;
				return;

			}else{

				recursive(TATE,changed_count,base_row,base_col+1);

			}

		}else{ //あれば、少なくとも、その区間の1つを変更

			if(changed_count == change_limit)return;

			for(int i = top; i <= under; i++){
				if(table[i][base_col] <= 0)continue;
				table[i][base_col] *= -1;
				recursive(TATE,changed_count+1,base_row,base_col);
				table[i][base_col] *= -1;
			}
		}
	}
}


int main(){


	scanf("%d %d %d %d",&H,&W,&change_limit,&base_num);

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++)scanf("%d",&table[row][col]);
	}

	//初期状態での、行の超過シーケンス数を数える


	//行
	int over_row_num = 0,tmp;
	queue<int> START;

	for(int row = 0; row < H; row++){
		START.push(0);

		int col,start;

		while(!START.empty()){
			start = START.front();
			START.pop();
			tmp = 0;
			for(col = start; col < W;){
				tmp += table[row][col];

				if(tmp < 0){ //start～colまでは、超過シーケンスなし
					if(col <= W-2){
						START.push(col+1);
					}
					break;
				}else if(tmp <= base_num){
					col++;
				}else if(tmp > base_num){
					over_row_num++;

					while(col+1 <= W-1 && tmp+table[row][col+1] > base_num){
						col++;
						tmp += table[row][col];
					}

					if(col <= W-2){
						START.push(col+1);
					}
					break;
				}
			}
		}
	}

	//printf("over_row: %d\n",over_row_num);

	//列
	int over_col_num = 0;
	for(int col = 0; col < W; col++){
		START.push(0);

		int row,start;

		while(!START.empty()){
			start = START.front();
			START.pop();
			tmp = 0;
			for(row = start; row < H;){
				tmp += table[row][col];

				if(tmp < 0){ //start～rowまでは、超過シーケンスなし
					if(row <= H-2){
						START.push(row+1);
					}
					break;
				}else if(tmp <= base_num){
					row++;
				}else if(tmp > base_num){
					over_col_num++;

					while(row+1 <= H-1 && tmp+table[row+1][col] > base_num){
						row++;
						tmp += table[row][col];
					}

					if(row <= H-2){
						START.push(row+1);
					}
					break;
				}
			}
		}
	}

	if(over_row_num == 0 && over_col_num == 0){
		printf("Yes\n");
		return 0;
	}

	if(change_limit < max(over_row_num,over_col_num)){ //反転回数の上限が、反転が必要な行数または列数より少ない
		printf("No\n");
		return 0;
	}

	FLG = false;

	recursive(YOKO,0,0,0);

	if(FLG){
		printf("Yes\n");
	}else{
		printf("No\n");
	}


	return 0;
}

