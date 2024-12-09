// La solucion se puede representar con un automata
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9
typedef pair<int,int> par;

map<int,int> T;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t;
	map<int,int>::iterator it;
	cin>>t;
	while(t--){
		int n,m,r,c;
		string ans = "YES";
		cin>>n>>m;
		for(int i=0; i<m; i++){
			cin>>r>>c;
			it = T.find(c);
			if(it == T.end())
			T.insert(par(c,r));
			else
			it->second = 0;
		}
		T.insert(par(n+1,0));

		int lastC = -1;
		int lastType = 0;
		for(it=T.begin(); it!=T.end() && ans == "YES"; it++){
			if(lastType == 0)
			lastType = it->second;
			else{
				if(lastType == 1){
					if((it->second == 0) || (it->second == 1 && (((it->first) - lastC) % 2 == 0)) || (it->second == 2 && (((it->first) - lastC) % 2 == 1)))
					ans = "NO";
				}
				else{
					if((it->second == 0) || (it->second == 1 && (((it->first) - lastC) % 2 == 1)) || (it->second == 2 && (((it->first) - lastC) % 2 == 0)))
					ans = "NO";
				}

				if(ans == "YES")
				lastType = 0;
			}

			lastC = it->first;
		}

		cout<<ans<<endl;
		T.clear();
	}
}