#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,l;
vector<string> str;
vector<int> G[1001];
int aim[1001];
bool used[1001];


bool check(int a,int b){
	for(int i=0;i<l;i++){
		if(str[a][i]!=str[b][l-1-i])return false;
	}
	return true;
}

bool checkme(int a){
	for(int i=0;i<l/2;i++){
		if(str[a][i]!=str[a][l-1-i])return false;
	}
	return true;
}

int main(void){
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++){
		string si;
		cin >> si;
		str.push_back(si);
	}
	sort(str.begin(),str.end());
	for(int i=0;i<n;i++){
		if(checkme(i))aim[i]=1;
		for(int j=i+1;j<n;j++){
			if(check(i,j)){
				G[i].push_back(j);
			}
		}
	}
	vector<string> resf;
	vector<string> rest;
	string resm="";
	for(int i=0;i<n;i++){
		if(used[i])continue;
		for(int j=0;j<G[i].size();j++){
			if(!used[G[i][j]]){
				used[i]=true;
				used[G[i][j]]=true;
				resf.push_back(str[i]);
				rest.push_back(str[G[i][j]]);
				break;
			}
		}
		if(!used[i] && aim[i]==1 && resm.size()==0){
			used[i]=true;
			resm+=str[i];
		}
	}
	string res="";
	for(int i=0;i<resf.size();i++){
		res+=resf[i];
	}
	res+=resm;
	for(int i=0;i<rest.size();i++){
		res+=rest[rest.size()-i-1];
	}
	cout << res << endl;
	return 0;
}