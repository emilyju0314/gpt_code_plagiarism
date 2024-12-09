#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 31

enum Type{
	CAN_EXIT,
	CAUGHT,
	INFINITE_LOOP,
};

enum Which{
	turn_Queen,
	turn_Army,
};

struct LOC{
	void set(int arg_row,int arg_col){
		row = arg_row;
		col = arg_col;
	}
	int row,col;
};

struct Info{
	Info(){
		Q_row = 0;
		Q_col = 0;
		A_row = 0;
		A_col = 0;
	}
	Info(int arg_Q_row,int arg_Q_col,int arg_A_row,int arg_A_col){
		Q_row = arg_Q_row;
		Q_col = arg_Q_col;
		A_row = arg_A_row;
		A_col = arg_A_col;
	}
	int Q_row,Q_col,A_row,A_col;
};

int W,H;
int diff_row[5] = {-1,0,0,0,1},diff_col[5] = {0,-1,0,1,0};
LOC Q_start,A_start;
char base_map[NUM][NUM+1];
Type table[NUM][NUM][NUM][NUM][2];
queue<Info> QUEEN[2],ARMY[2];


bool rangeCheck(int row,int col){

	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1 && base_map[row][col] != '#'){

		return true;
	}else{
		return false;
	}
}

void init_dp(){

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			for(int row2 = 0; row2 < H; row2++){
				for(int col2 = 0; col2 < W; col2++){
					table[row][col][row2][col2][turn_Queen] = INFINITE_LOOP;
					table[row][col][row2][col2][turn_Army] = INFINITE_LOOP;
				}
			}
		}
	}
}

void set_exit(int exit_row,int exit_col){

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			table[exit_row][exit_col][row][col][turn_Queen] = CAN_EXIT;
		}
	}
}

void set_caught(){

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			table[row][col][row][col][turn_Queen] = CAUGHT;
			table[row][col][row][col][turn_Army] = CAUGHT;
		}
	}
}

void func(){

	init_dp();

	for(int i = 0; i < 2; i++){
		while(!QUEEN[i].empty())QUEEN[i].pop();
		while(!ARMY[i].empty())ARMY[i].pop();
	}

	for(int row = 0; row < H; row++){

		scanf("%s",base_map[row]);

		for(int col = 0; col < W; col++){

			if(base_map[row][col] == 'Q'){

				Q_start.set(row,col);

			}else if(base_map[row][col] == 'A'){

				A_start.set(row,col);

			}else if(base_map[row][col] == 'E'){

				set_exit(row,col);
			}
		}
	}

	set_caught();

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			for(int row2 = 0; row2 < H; row2++){
				for(int col2 = 0; col2 < W; col2++){
					if(table[row][col][row2][col2][turn_Queen] == INFINITE_LOOP){
						QUEEN[0].push(Info(row,col,row2,col2));
					}
					if(table[row][col][row2][col2][turn_Army] == INFINITE_LOOP){
						ARMY[0].push(Info(row,col,row2,col2));
					}
				}
			}
		}
	}

	bool FLG;
	int CURRENT = 0,NEXT = 1;
	Info info;
	int adj_row,adj_col;
	bool exit_FLG,caught_FLG;

	while(true){

		FLG = false;

		while(!QUEEN[CURRENT].empty()){

			info = QUEEN[CURRENT].front();
			QUEEN[CURRENT].pop();

			if(table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Queen] != INFINITE_LOOP){
				continue;
			}
			exit_FLG = false;
			caught_FLG = true;

			for(int i = 0; i < 5; i++){

				adj_row = info.Q_row+diff_row[i];
				adj_col = info.Q_col+diff_col[i];

				if(!rangeCheck(adj_row,adj_col))continue;

				if(table[adj_row][adj_col][info.A_row][info.A_col][turn_Army] == CAN_EXIT){
					exit_FLG = true;
				}

				if(table[adj_row][adj_col][info.A_row][info.A_col][turn_Army] != CAUGHT){
					caught_FLG = false;
				}
			}

			if(exit_FLG){
				table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Queen] = CAN_EXIT;
				FLG = true;
			}

			if(caught_FLG){
				table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Queen] = CAUGHT;
				FLG = true;
			}

			if(exit_FLG == false && caught_FLG == false){
				QUEEN[NEXT].push(info);
			}
		}

		while(!ARMY[CURRENT].empty()){

			info = ARMY[CURRENT].front();
			ARMY[CURRENT].pop();

			if(table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Army] != INFINITE_LOOP){
				continue;
			}
			exit_FLG = true;
			caught_FLG = false;

			for(int i = 0; i < 5; i++){

				adj_row = info.A_row+diff_row[i];
				adj_col = info.A_col+diff_col[i];

				if(!rangeCheck(adj_row,adj_col))continue;

				if(table[info.Q_row][info.Q_col][adj_row][adj_col][turn_Queen] == CAUGHT){
					caught_FLG = true;
				}

				if(table[info.Q_row][info.Q_col][adj_row][adj_col][turn_Queen] != CAN_EXIT){
					exit_FLG = false;
				}
			}

			if(exit_FLG){
				table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Army] = CAN_EXIT;
				FLG = true;
			}

			if(caught_FLG){
				table[info.Q_row][info.Q_col][info.A_row][info.A_col][turn_Army] = CAUGHT;
				FLG = true;
			}

			if(exit_FLG == false && caught_FLG == false){
				ARMY[NEXT].push(info);
			}
		}

		if(!FLG)break;

		swap(CURRENT,NEXT);
	}

	switch(table[Q_start.row][Q_start.col][A_start.row][A_start.col][turn_Queen]){
	case CAN_EXIT:
		printf("Queen can escape.\n");
		break;
	case CAUGHT:
		printf("Army can catch Queen.\n");
		break;
	case INFINITE_LOOP:
		printf("Queen can not escape and Army can not catch Queen.\n");
		break;
	}
}

int main(){

	while(true){
		scanf("%d %d",&W,&H);
		if(W == 0 && H == 0)break;

		func();
	}

	return 0;
}

