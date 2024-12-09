#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 12

enum DIR{
	N,
	E,
	S,
	W,
};

enum Type{
	Plane,
	N_S,
	W_E,
	N_E,
	S_E,
	W_S,
	W_N,
	W_Plane,
	N_Plane,
	E_Plane,
	S_Plane,
	Cross,
};


int R,C;
int input[SIZE];
int POW[16];
int num_tile;
ll dp[8][1024*32][11];
vector<int> BIT[1024*32][12];
bool table[SIZE][4];
Type type[15],type_array[SIZE] = {Plane,N_S,W_E,N_E,S_E,W_S,W_N,W_Plane,N_Plane,E_Plane,S_Plane,Cross};



//あるタイルについては、その割り当てビットが左にあるものから使う
int calc_next_state(int rest_state,int USE[3]){

	int index[SIZE] = {0};

	int ret = rest_state;

	for(int i = 0; i < R; i++){
		ret -= POW[BIT[rest_state][USE[i]][index[USE[i]]++]];
	}

	return ret;
}

/*
 * 接続状態
 *
 * 行数1: (0:左端と連結)/(1:左端と非連結)
 * 行数2: (0:全て左上と連結)/(1:行0のみが左上と連結)/(2:行1のみが左上と連結)/(3:全て左上と非連結)
 * 行数3: (0:全て左上と連結)/(1:行0,1が左上と連結)/(2:行0,2が左上と連結)/(3:行1,2が左上と連結)
 *        (4:行0のみが左上と連結,行1,2が連結)/(5:行1のみが左上と連結,行0,2が連結)/(6:行2のみが左上と連結,行0,1が連結)
 * 	      (7:行0のみが左上と連結,行1,2が非連結)/(8:行1のみが左上と連結,行0,2が非連結)/(9:行2のみが左上と連結,行0,1が非連結)
 *        (10:全て左上と非連結)
 *
 * */


ll recursive(int col,int pre_E_state,int rest_state,int pre_con_state){

	if(col == C){

		switch(R){
		case 1:
			if(pre_con_state == 0){

				return 1;

			}else{

				return 0;
			}

			break;
		case 2:
			if(pre_con_state == 0 || pre_con_state == 2){

				return 1;
			}else{

				return 0;
			}
			break;
		case 3:
			if(pre_con_state == 0 || pre_con_state == 2 || pre_con_state == 3 || pre_con_state == 6 ||
					pre_con_state == 9){

				return 1;
			}else{

				return 0;
			}
			break;
		}
	}

	if(dp[pre_E_state][rest_state][pre_con_state] != -1){

		return dp[pre_E_state][rest_state][pre_con_state];
	}

	//左上と連結しているタイルが1毎もないなら打ち切り
	if(col >= 1){

		if(pre_E_state == 0){

			return 0;
		}

		switch(R){
		case 1:
			if(pre_con_state == 1){

				return 0;
			}
			break;
		case 2:
			if(pre_con_state == 3){

				return 0;
			}
			break;
		case 3:
			if(pre_con_state == 10){

				return 0;
			}
			break;
		}
	}

	ll ret = 0;

	int pre[3],now[3],T[3];

	switch(R){
	case 1:

		switch(pre_con_state){
		case 0:

			pre[0] = 1; //1:左上と同じグループ
			break;
		case 1:

			pre[0] = 2;
			break;
		}
		break;

	case 2:

		switch(pre_con_state){
		case 0:
			pre[0] = 1;
			pre[1] = 1;
			break;
		case 1:
			pre[0] = 1;
			pre[1] = 2;
			break;
		case 2:
			pre[0] = 2;
			pre[1] = 1;
			break;
		case 3:
			pre[0] = 2;
			pre[1] = 2;
			break;
		}
		break;

	case 3:
		switch(pre_con_state){
		case 0:
			pre[0] = 1;
			pre[1] = 1;
			pre[2] = 1;
			break;
		case 1:
			pre[0] = 1;
			pre[1] = 1;
			pre[2] = 2;
			break;
		case 2:
			pre[0] = 1;
			pre[1] = 2;
			pre[2] = 1;
			break;
		case 3:
			pre[0] = 2;
			pre[1] = 1;
			pre[2] = 1;
			break;
		case 4:
			pre[0] = 1;
			pre[1] = 2;
			pre[2] = 2;
			break;
		case 5:
			pre[0] = 2;
			pre[1] = 1;
			pre[2] = 2;
			break;
		case 6:
			pre[0] = 2;
			pre[1] = 2;
			pre[2] = 1;
			break;
		case 7:
			pre[0] = 1;
			pre[1] = 2;
			pre[2] = 3;
			break;
		case 8:
			pre[0] = 2;
			pre[1] = 1;
			pre[2] = 3;
			break;
		case 9:
			pre[0] = 2;
			pre[1] = 3;
			pre[2] = 1;
			break;
		case 10:
			pre[0] = 2;
			pre[1] = 2;
			pre[2] = 2;
			break;
		}
		break;
	}

	//どのタイルが何枚残っているのかを計算
	int work[SIZE] = {0};

	for(int loop = 0; loop < num_tile; loop++){
		if(rest_state & POW[loop]){

			work[type[loop]]++;
		}
	}

	vector<int> V;
	for(int i = 0; i < SIZE; i++){
		if(work[i] > 0){
			V.push_back(i);
		}
	}

	int USE[3] = {0};
	int next_E_state,next_con_state,next_rest_state;


	switch(R){
	case 1: //1枚選ぶ

		for(int a = 0; a < SIZE; a++){
			if(work[a] == 0)continue;
			USE[0] = a;

			next_rest_state = calc_next_state(rest_state,USE);

			if(col == 0){

				if(a == Plane){

					next_con_state = 1;

				}else{

					next_con_state = 0;
				}

			}else{

				if(pre[0] == 1 && table[a][W]){

					next_con_state = 0;

				}else{

					next_con_state = 1;
				}
			}

			ret += recursive(col+1,table[a][E],next_rest_state,next_con_state);
		}

		break;
	case 2: //2枚選ぶ

		for(int a = 0; a < SIZE; a++){
			if(work[a] == 0)continue;
			T[0] = a;
			USE[0] = a;
			for(int b = 0; b < SIZE; b++){
				if(work[b] == 0)continue;
				if(a == b && work[a] <= 1)continue;
				T[1] = b;
				USE[1] = b;


				next_rest_state = calc_next_state(rest_state,USE);
				next_E_state = 0;
				for(int i = 0; i < 2; i++){
					if(table[T[i]][E]){

						next_E_state += POW[i];
					}
				}

				if(col == 0){

					//行0
					if(T[0] == Plane){

						now[0] = 2;

					}else{

						now[0] = 1;
					}

					//行1
					if(table[T[0]][S] && table[T[1]][N]){

						now[1] = now[0];

					}else{

						now[1] = now[0]+1;
					}

				}else{ //col >= 1

					//まずは左→右の遷移を見る
					for(int i = 0; i < 2; i++){

						//左のセルが右に接続可で、T[i]が左に接続可
						if(((pre_E_state & POW[i]) != 0) && table[T[i]][W]){

							now[i] = pre[i];

						}else{

							now[i] = i+3;
						}
					}

					//上→下の遷移を見る
					if(now[0] != now[1] && table[T[0]][S] && table[T[1]][N]){

						if(now[0] == 1){

							now[1] = 1;

						}else if(now[1] == 1){

							now[0] = 1;

						}else{

							now[0] = 2;
							now[1] = 2;
						}
					}
				}

				//next_con_state
				if(now[0] == now[1]){

					if(now[0] == 1){

						next_con_state = 0;

					}else{

						next_con_state = 3;
					}

				}else{ //now[0] != now[1]

					if(now[0] == 1){

						next_con_state = 1;
					}else if(now[1] == 1){

						next_con_state = 2;

					}else{

						next_con_state = 3;
					}
				}

				ret += recursive(col+1,next_E_state,next_rest_state,next_con_state);
			}
		}

		break;
	case 3: //3枚選ぶ

		for(int a = 0; a < V.size(); a++){
			T[0] = V[a];
			USE[0] = V[a];
			for(int b = 0; b < V.size(); b++){
				if(a == b && work[V[a]] <= 1)continue;
				T[1] = V[b];
				USE[1] = V[b];
				for(int c = 0; c < V.size(); c++){
					if(work[V[c]] == 0)continue;
					if(a == c && work[V[a]] <= 1)continue;
					if(b == c && work[V[b]] <= 1)continue;
					if(a == c && b == c && work[V[a]] <= 2)continue;
					T[2] = V[c];
					USE[2] = V[c];

					next_rest_state = calc_next_state(rest_state,USE);
					next_E_state = 0;

					for(int i = 0; i < 3; i++){
						if(table[T[i]][E]){

							next_E_state += POW[i];
						}
					}

					if(col == 0){

						if(T[0] == Plane){

							now[0] = 2;

						}else{

							now[0] = 1;
						}
						if(table[T[0]][S] && table[T[1]][N]){

							now[1] = now[0];

						}else{

							now[1] = now[0]+1;
						}
						if(table[T[1]][S] && table[T[2]][N]){

							now[2] = now[1];
						}else{

							now[2] = now[1]+1;
						}

					}else{ //col >= 1

						//まずは左→右の遷移を見る
						for(int i = 0; i < 3; i++){

							//左のセルが1で右に接続可で、T[i]が左に接続可
							if(((pre_E_state & POW[i]) != 0) && table[T[i]][W]){

								now[i] = pre[i];

							}else{

								now[i] = i+4;
							}
						}

						//1のセルがあったら優先して処理

						//上→下へ
						if(now[0] == 1 && now[1] != 1 && table[T[0]][S] && table[T[1]][N]){

							now[1] = 1;
						}
						if(now[1] == 1 && now[2] != 1 && table[T[1]][S] && table[T[2]][N]){

							now[2] = 1;
						}
						//下→上へ
						if(now[2] == 1 && now[1] != 1 && table[T[1]][S] && table[T[2]][N]){

							now[1] = 1;
						}
						if(now[1] == 1 && now[0] != 1 && table[T[0]][S] && table[T[1]][N]){

							now[0] = 1;
						}

						//己型
						if(now[1] == 1 && now[2] != 1 && pre[1] == pre[2] && ((pre_E_state & POW[1]) > 0) &&
								table[T[1]][W] && ((pre_E_state & POW[2]) > 0)	&& table[T[2]][W]){

							now[2] = 1;
						}
						//逆己型
						if(now[1] == 1 && now[0] != 1 && pre[1] == pre[0] && ((pre_E_state & POW[1]) > 0) &&
								table[T[1]][W] &&  ((pre_E_state & POW[0]) > 0)	&& table[T[0]][W]){

							now[0] = 1;
						}

						//1以外の更新
						if(now[0] != 1 && now[1] != 1 && now[0] != now[1] && table[T[0]][S] && table[T[1]][N]){

							now[1] = now[0];
						}
						if(now[1] != 1 && now[2] != 1 && now[1] != now[2] && table[T[1]][S] && table[T[2]][N]){

							now[2] = now[1];
						}
						//己型
						if(now[1] != 1 && now[2] != 1 && pre[1] == pre[2] && ((pre_E_state & POW[1]) > 0) &&
								table[T[1]][W] && ((pre_E_state & POW[2]) > 0)	&& table[T[2]][W]){

							now[2] = now[1];
						}
						//逆己型
						if(now[1] != 1 && now[0] != 1 && pre[1] == pre[0] && ((pre_E_state & POW[1]) > 0) &&
								table[T[1]][W] &&  ((pre_E_state & POW[0]) > 0)	&& table[T[0]][W]){

							now[1] = now[0];
						}
					}

					if(now[0] == now[1] && now[0] == now[2]){ //3つ同じ

						if(now[0] == 1){

							next_con_state = 0;

						}else{

							next_con_state = 10;
						}

					}else if(now[0] == now[1]){

						if(now[0] == 1){

							next_con_state = 1;

						}else{

							if(now[2] == 1){

								next_con_state = 6;

							}else{

								next_con_state = 10;
							}
						}

					}else if(now[0] == now[2]){

						if(now[0] == 1){

							next_con_state = 2;

						}else{

							if(now[1] == 1){

								next_con_state = 5;

							}else{

								next_con_state = 10;
							}
						}

					}else if(now[1] == now[2]){

						if(now[1] == 1){

							next_con_state = 3;

						}else{

							if(now[0] == 1){

								next_con_state = 4;

							}else{

								next_con_state = 10;
							}
						}


					}else{ //全部違う

						if(now[0] == 1){

							next_con_state = 7;

						}else if(now[1] == 1){

							next_con_state = 8;

						}else if(now[2] == 1){

							next_con_state = 9;

						}else{

							next_con_state = 10;
						}
					}

					ret += recursive(col+1,next_E_state,next_rest_state,next_con_state);
				}
			}
		}

		break;
	}

	return dp[pre_E_state][rest_state][pre_con_state] = ret;
}

int main(){

	POW[0] = 1;
	for(int i = 1; i <= 15; i++){

		POW[i] = POW[i-1]*2;
	}

	//Plane
	table[Plane][N] = false,table[Plane][E] = false,table[Plane][S] = false,table[Plane][W] = false;
	//sigle load
	table[N_S][N] = true,table[N_S][E] = false,table[N_S][S] = true,table[N_S][W] = false;
	table[W_E][N] = false,table[W_E][E] = true,table[W_E][S] = false,table[W_E][W] = true;
	table[N_E][N] = true,table[N_E][E] = true,table[N_E][S] = false,table[N_E][W] = false;
	table[S_E][N] = false,table[S_E][E] = true,table[S_E][S] = true,table[S_E][W] = false;
	table[W_S][N] = false,table[W_S][E] = false,table[W_S][S] = true,table[W_S][W] = true;
	table[W_N][N] = true,table[W_N][E] = false,table[W_N][S] = false,table[W_N][W] = true;
	//three-forked-load
	table[W_Plane][N] = true,table[W_Plane][E] = true,table[W_Plane][S] = true,table[W_Plane][W] = false;
	table[N_Plane][N] = false,table[N_Plane][E] = true,table[N_Plane][S] = true,table[N_Plane][W] = true;
	table[E_Plane][N] = true,table[E_Plane][E] = false,table[E_Plane][S] = true,table[E_Plane][W] = true;
	table[S_Plane][N] = true,table[S_Plane][E] = true,table[S_Plane][S] = false,table[S_Plane][W] = true;
	//Cross
	table[Cross][N] = true,table[Cross][E] = true,table[Cross][S] = true,table[Cross][W] = true;


	scanf("%d %d",&R,&C);
	for(int i = 0; i < SIZE; i++){

		scanf("%d",&input[i]);
	}

	if(R > C){

		/*
		 * 行と列を交換→右に90度倒して、左右を反転させる
		 * */

		swap(R,C);
		swap(input[W_E],input[N_S]);
		swap(input[N_E],input[W_S]);
		swap(input[S_Plane],input[E_Plane]);
		swap(input[N_Plane],input[W_Plane]);
	}

	//ビットの各桁に各タイルを割り当てる
	num_tile = 0;
	for(int i = 0; i < SIZE; i++){
		for(int k = 0; k < input[i]; k++){

			type[num_tile] = type_array[i];
			num_tile++;
		}
	}

	if(num_tile < R*C){

		printf("0\n");
		return 0;
	}

	for(int i = 0; i < POW[R]; i++){
		for(int k = 0; k < POW[num_tile]; k++){
			for(int a = 0; a < 11; a++){

				dp[i][k][a] = -1;
			}
		}
	}

	//ビットが立っている場所を前計算
	for(int state = 0; state < POW[num_tile]; state++){
		for(int loop = 0; loop < num_tile; loop++){
			if(state & POW[loop]){
				BIT[state][type[loop]].push_back(loop);
			}
		}
	}

	int first_pre;
	switch(R){
	case 1:
		first_pre = 1;
		break;
	case 2:
		first_pre = 3;
		break;
	case 3:
		first_pre = 10;
		break;
	}

	printf("%lld\n",recursive(0,0,POW[num_tile]-1,first_pre));

	return 0;
}

