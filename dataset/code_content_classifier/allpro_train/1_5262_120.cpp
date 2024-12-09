#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define MAX_N 100000
int N, M;
int par[MAX_N + 1];
int arr[MAX_N + 1];

int root(int x){

	if(par[x] == x)	return par[x];

	return par[x] = root(par[x]);

}

void unite(int x, int y){
  int rx = root(x);
  int ry = root(y);

  if(rx == ry)	return;
  par[rx] = par[ry];
}

bool same(int x, int y){
 return root(x) == root(y);
}



int main(void){

	cin >> N >> M;
	for(int i = 1 ; i <= N ; i++){
		cin >> arr[i];
		par[i] = i;
	}

	//木がくっついていれば入れ替えられる
	for(int i = 0 ; i < M ; i++){
		int x, y;
		cin >> x >> y;
		unite(x , y);
	}

	int ans = 0;
	for(int i = 1 ; i <= N ; i++){
	 	if(arr[i] == i)	ans++;
		else if(same(arr[i] , i))	ans++;
	}
	
		  
	cout << ans << endl;

 return 0;
}
