#include<iostream>
#include<vector>
#include<string>

#define N 11

using namespace std;

struct food{
	string name;
	int w;
	int s;
};

void dfs(int n, const vector<food> &f, bool flag[N], vector<food> &now, double &bestG, vector<food> &ans){
	int sumwG_denom = 0;
	int sumwG_numer = 0;
	double nowG = 0;

	for(unsigned int i = 0; i < now.size(); ++i){
		int sumw = 0;
		sumwG_numer += (i+1)*now[i].w;
		sumwG_denom += now[i].w;
		for(unsigned int j = i + 1; j < now.size(); ++j){
			sumw += now[j].w;
		}
		if( sumw > now[i].s )
			return ;
	}
	if( sumwG_denom > 0 ){
		nowG = sumwG_numer / (double)sumwG_denom;
		
		
		/*if( now.size() == n ){
			cout << " ------------------ \n";
			for(unsigned int i = 0; i < now.size(); ++i){
				cout << now[i].name << endl;
			}
			cout << "BEST : " << bestG << " G: " << nowG << endl;
		}*/
		

		if( now.size() == n && nowG < bestG ){
			bestG = nowG;
			ans = now;
		}
	}
	
	for(unsigned int i = 0; i < f.size(); ++i){
		if( !flag[i] ){
			flag[i] = true;
			now.push_back( f[i] );
			dfs( n, f, flag, now, bestG, ans );
			now.erase( now.end() - 1 );
			flag[i] = false;
		}
	}
}

int main(){
	while(true){
		int n;
		double bestG = 1000000;
		bool flag[N] = {false,};
		vector< food > vfoods, init, ans;
		
		cin>>n;
		if(n==0)break;
		for(int i = 0; i < n; ++i){
			food f;
			cin>>f.name>>f.w>>f.s;
			vfoods.push_back( f );
		}
		dfs( n, vfoods, flag, init, bestG, ans );
		for(unsigned int i = 0; i < ans.size(); ++i){
			cout << ans[i].name << endl;
		}
	}
	return 0;
}