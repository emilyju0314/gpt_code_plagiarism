#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reep(i,a,b) for(int i=a; i<b; i++)

using namespace std;


void solve(int n){
	vector<string> v(n);
	rep(i,n){
		cin>>v[i];
	}
	map<string,int> used;
	vector<int> type(n),num(n);
	vector<int> par(n,-1);
	vector<int> start(n, 1);
	rep(i,n){
		string t = v[i];
		int val = 0;
		int pp = 1;
		if(t.back() == 'v'){
			t = t.substr(0, t.size()-1);
			par[i+1] = i;
			start[i] = 0;
		}
		if(t.size() == 0){
			continue;
		}
		if(t == "-"){
			continue;
		}
		int len = t.size();
		while(isdigit(t[len-1])){
			len--;
			val += pp*(t[len]-'0');
			pp *= 10;
		}
		t = t.substr(0, len);
		if(val > 1){
			start[i] = 0;
		}
		if(used.count(t) == 0){
			if(val > 1){
				used[t] = i;
			}
		}
		else{
			par[i] = used[t];
			if(val > 1){
				used[t] = i;
			}
			else{
				used.erase(t);
			}
		}
	}
	/*
	rep(i,n){
		cout<<i<<" "<<par[i]<<endl;
	}
	cout<<endl;
	*/
	int pos = 0;
	while(pos < n){
		if(start[pos]){
			int t = pos;
			while(t >= 0){
				cout<<t+1<<endl;
				t = par[t];
			}			
		}
		pos++;
	}
}			
					



int main(){
	int n;
	while(cin>>n, n){
		solve(n);
	}
}