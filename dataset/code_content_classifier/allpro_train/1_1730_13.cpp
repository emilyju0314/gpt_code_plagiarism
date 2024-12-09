#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

int first_N,N;
vector<string> words,rev_words;
vector<int> rev_index;
vector<int> data[8*NUM];


void init(int first_N){
	while(N < first_N)N *= 2;
}

void build(int node_id,int node_left,int node_right){

	if(node_right == node_left){

		if(node_left < first_N){
			data[node_id].push_back(rev_index[node_left]);
		}else{
			data[node_id].push_back(BIG_NUM);
		}
	}else{

		build(2*node_id+1,node_left,(node_left+node_right)/2);
		build(2*node_id+2,(node_left+node_right)/2+1,node_right);

		data[node_id].resize(node_right-node_left+1);
		merge(data[2*node_id+1].begin(),data[2*node_id+1].end(),data[2*node_id+2].begin(),
				data[2*node_id+2].end(),data[node_id].begin());
	}
}

//D未満の数を求める
int query(int search_left,int search_right,int node_id,int node_left,int node_right,int D){

	if(search_right < node_left || search_left > node_right)return 0;

	if(search_left <= node_left && search_right >= node_right){

		if(data[node_id][data[node_id].size()-1] < D){ //Dが最大値より大きい

			return (int)data[node_id].size();

		}else if(data[node_id][0] >= D){ //Dが最小値以上

			return 0;
		}

		int index,L,R,mid;

		//D未満の最大の数字を二分探索で検索
		L = 0,R = data[node_id].size()-1,mid = (L+R)/2;

		while(L <= R){

			if(data[node_id][mid] < D){

				index = mid;
				L = mid+1;
			}else{

				R = mid-1;
			}
			mid = (L+R)/2;
		}

		return index+1;
	}

	//今回のノードの区間に、一部検索区間と重なっている区間がある場合→再帰的に子どもに尋ねる
	int left_num = query(search_left,search_right,2*node_id+1,node_left,(node_left+node_right)/2,D);
	int right_num = query(search_left,search_right,2*node_id+2,(node_left+node_right)/2+1,node_right,D);

	return left_num+right_num;
}

int main(){

	int num_query;

	cin >> first_N >> num_query;

	for(int i = 0; i < first_N; i++){

		string input_str;
		cin >> input_str;

		words.push_back(input_str);
		reverse(input_str.begin(),input_str.end());
		rev_words.push_back(input_str);
	}

	sort(words.begin(),words.end());
	sort(rev_words.begin(),rev_words.end());

	//words[i]が、rev_words[i]のどこにあるかを調べる
	for(int i = 0; i < first_N; i++){

		string tmp = words[i];
		reverse(tmp.begin(),tmp.end());
		rev_index.push_back(lower_bound(rev_words.begin(),rev_words.end(),tmp)-rev_words.begin());
	}

	N = 1;
	init(first_N);

	build(0,0,N-1); //セグ木の構築

	int left,right,top,under;

	for(int loop = 0; loop < num_query; loop++){

		string prefix,suffix;

		cin >> prefix >> suffix;
		reverse(suffix.begin(),suffix.end());

		left = lower_bound(words.begin(),words.end(),prefix)-words.begin();
		right = lower_bound(words.begin(),words.end(),prefix+'~')-words.begin();

		top = lower_bound(rev_words.begin(),rev_words.end(),suffix)-rev_words.begin();
		under = lower_bound(rev_words.begin(),rev_words.end(),suffix+'~')-rev_words.begin();

		printf("%d\n",query(left,right-1,0,0,N-1,under)-query(left,right-1,0,0,N-1,top));
	}

	return 0;
}


