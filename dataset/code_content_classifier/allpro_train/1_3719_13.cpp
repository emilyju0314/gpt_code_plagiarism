#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 20
#define NUM 100


struct Info{
	int limit_count,need_time;
};

struct Data{
	int order_time,rest_num,table[SIZE];
};

int num_menu,num_order,case_num;
int ans[NUM];
char name[SIZE][SIZE+1];
Info info[SIZE];
Data data[NUM];


bool strCmp(char* base, char* comp){
	int length1,length2;
	for(length1=0;base[length1] != '\0';length1++);
	for(length2=0;comp[length2] != '\0';length2++);
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

void func(){

	if(case_num > 0){
		printf("\n");
	}

	//メニュー情報の取得
	for(int i = 0; i < num_menu; i++){
		scanf("%s %d %d",name[i],&info[i].limit_count,&info[i].need_time);
	}

	for(int i = 0; i < num_order; i++){
		for(int k = 0; k < num_menu; k++){
			data[i].table[k] = 0;
		}
	}

	char buf[SIZE+1];

	//注文情報の取得
	for(int i = 0; i < num_order; i++){

		scanf("%d %d",&data[i].order_time,&data[i].rest_num);
		for(int k = 0; k < data[i].rest_num; k++){
			scanf("%s",buf);
			for(int a = 0; a < num_menu; a++){
				if(strCmp(name[a],buf)){
					data[i].table[a]++;
					break;
				}
			}
		}
	}

	int current_time = 0,order_index = 0;
	int max_time,max_id,can_make_num;
	queue<int> other_order;

	while(order_index < num_order){

		if(current_time < data[order_index].order_time){
			current_time = data[order_index].order_time;
		}

		//現在の注文が全て処理されるまではループ
		while(data[order_index].rest_num > 0){

			max_time = -BIG_NUM;
			for(int i = 0; i < num_menu; i++){
				if(data[order_index].table[i] == 0)continue;
				//最も準備に時間のかかるメニューを選ぶ
				if(max_time < info[i].need_time){
					max_time = info[i].need_time;
					max_id = i;
				}
			}

			if(info[max_id].limit_count < data[order_index].table[max_id]){ //注文個数よりも、同時作成可能個数が少ない場合

				data[order_index].rest_num -= info[max_id].limit_count;
				data[order_index].table[max_id] -= info[max_id].limit_count;
				current_time += info[max_id].need_time;

			}else{ //★★注文が完成する可能性があるので注意★★

				can_make_num = info[max_id].limit_count-data[order_index].table[max_id];

				data[order_index].rest_num -= data[order_index].table[max_id]; //★★注意:rest_numは種類数でなく、注文の総数★★
				data[order_index].table[max_id] = 0;

				if(data[order_index].rest_num == 0){
					ans[order_index] = current_time+info[max_id].need_time;
				}

				//★この時点で届いている注文で、同じメニューがあれば、同時に作る★
				for(int i = order_index+1; i < num_order && data[i].order_time <= current_time && can_make_num > 0; i++){
					if(data[i].table[max_id] > 0){
						if(can_make_num < data[i].table[max_id]){

							data[i].rest_num -= can_make_num;
							data[i].table[max_id] -= can_make_num;
							can_make_num = 0;

						}else{

							can_make_num -= data[i].table[max_id];
							data[i].rest_num -= data[i].table[max_id];
							data[i].table[max_id] = 0;

							if(data[i].rest_num == 0){
								ans[i] = current_time+info[max_id].need_time;
							}
						}
					}
				}

				current_time += info[max_id].need_time;
			}

		}
		order_index++;
	}

	for(int i = 0; i < num_order; i++){
		printf("%d\n",ans[i]);
	}
}

int main(){

	case_num = 0;

	while(true){
		scanf("%d %d",&num_menu,&num_order);
		if(num_menu == 0 && num_order == 0)break;

		func();
		case_num++;
	}

	return 0;
}

