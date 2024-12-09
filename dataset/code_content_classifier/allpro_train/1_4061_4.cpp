#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 305

struct Info{
	Info(int arg_ancestor,int arg_descendant){
		ancestor = arg_ancestor;
		descendant = arg_descendant;
	}
	int ancestor,descendant;
};

int name_index,N;
map<string,int> MAP;
vector<int> RELATION[NUM][NUM];
vector<Info> DOCUMENT[1005];
bool check[NUM][NUM];
bool decided[1005],visited[NUM];


int get_index(string tmp_str){

	auto at = MAP.find(tmp_str);

	if(at == MAP.end()){

		MAP[tmp_str] = name_index++;
	}
	return MAP[tmp_str];
}

void bfs(int start_index){

	for(int i = 0; i < name_index; i++){
		visited[i] = false;
	}
	visited[start_index] = true;

	queue<int> Q;
	Q.push(start_index);

	while(!Q.empty()){

		for(int i = 0; i < name_index; i++){
			if(!check[Q.front()][i])continue;

			if(visited[i] == false){
				visited[i] = true;
				check[start_index][i] = true;
				Q.push(i);
			}
		}
		Q.pop();
	}
}

int main(){

	name_index = 0;

	string ANC,DES;

	cin >> ANC >> DES;

	int first_ancestor = get_index(ANC);
	int first_descendant = get_index(DES);

	scanf("%d",&N);

	int tmp_num,tmp_anc,tmp_des;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp_num);

		for(int loop = 0; loop < tmp_num; loop++){

			cin >> ANC >> DES;
			tmp_anc = get_index(ANC);
			tmp_des = get_index(DES);

			RELATION[tmp_anc][tmp_des].push_back(i);
			DOCUMENT[i].push_back(Info(tmp_anc,tmp_des));
		}
	}

	for(int i = 0; i < name_index; i++){
		for(int k = 0; k < name_index; k++){
			check[i][k] = false;
		}
	}

	for(int i = 0; i < N; i++){
		decided[i] = false;
	}

	queue<Info> Q;
	Q.push(Info(first_ancestor,first_descendant));

	int tmp_document;

	while(!Q.empty()){

		if(check[Q.front().ancestor][Q.front().descendant]){

			Q.pop();

		}else{

			check[Q.front().ancestor][Q.front().descendant] = true;

			for(int i = 0; i < RELATION[Q.front().ancestor][Q.front().descendant].size(); i++){

				tmp_document = RELATION[Q.front().ancestor][Q.front().descendant][i];

				if(decided[tmp_document])continue;

				decided[tmp_document] = true;
				for(int k = 0; k < DOCUMENT[tmp_document].size(); k++){
					Q.push(DOCUMENT[tmp_document][k]);
				}
			}

			for(int i = 0; i < name_index; i++){
				if(check[Q.front().descendant][i] == false || check[Q.front().ancestor][i] == true)continue;
				Q.push(Info(Q.front().ancestor,i));
			}

			for(int i = 0; i < name_index; i++){
				if(check[i][Q.front().ancestor] == false || check[i][Q.front().descendant] == true)continue;
				Q.push(Info(i,Q.front().descendant));
			}
			Q.pop();
		}
	}

	for(int i = 0; i < name_index; i++){
		bfs(i);
	}

	for(int i = 0; i < name_index; i++){
		for(int k = 0; k < name_index; k++){
			if(k == i || check[i][k] == false)continue;

			if(check[k][i]){
				printf("No\n");
				return 0;
			}
		}
	}

	printf("Yes\n");

	return 0;
}

