
#include <bits/stdc++.h>
using namespace std;

#define DBG(x) ;//cerr << #x << " = " << x << endl

int N,M;
int s[234567],t[234567];
vector<int>G[234567];
vector<pair<int,int>>nG[234567];//bridge:positive,others:0
vector<int>pG[234567];//forest

int af[234567];
int dpar[234567];
vector<int>dch[234567];
int imos[234567];
bool dok[234567];
int cntcnt = 0;
void dfs1(int x){
	af[x] = cntcnt;
	++cntcnt;
	for(int ch:G[x]){
		if(af[ch]<0){
			dpar[ch]=x;
			dfs1(ch);
		}
	}
}
int dfs2(int x){
	//cerr<<x<<"!!!!!!!!!!!!!"<<endl;
	for(int ch:dch[x]){
		//cerr<<ch<<"<-----"<<x<<endl;
		//if(dpar[ch]==x){
			imos[x]+=dfs2(ch);
		//}
	}
	DBG(x);
	DBG(imos[x]);
	return imos[x];
}

int id[234567];
int idcnt[234567];
void dfs3(int x,int ls,int nid){
	id[x]=nid;
	for(auto pp:nG[x]){
		if(pp.second!=0)continue;
		int ch = pp.first;
		if(ch!=ls){
			if(id[ch] < 0){
				dfs3(ch,x,nid);
			}
		}
	}
}

int memo[234567][2];
int dp(int x,int k,int ls=-1){
	if(k==-1)return max(dp(x,0,ls),dp(x,1,ls));
	if(memo[x][k]>=0)return memo[x][k];
	int res = k ? idcnt[x] : 0;
	if(k){
		for(int ch:pG[x]){
			if(ch!=ls){
				res+=dp(ch,0,x);
			}
		}
	}else{
		for(int ch:pG[x]){
			if(ch!=ls){
				res+=dp(ch,-1,x);
			}
		}
	}
	return memo[x][k]=res;
}

int main(){
	cin>>N>>M;
	for(int j=0;j<M;++j){
		cin>>s[j]>>t[j];
		G[s[j]].push_back(t[j]);
		G[t[j]].push_back(s[j]);
	}
	fill(af,af+N,-1);
	fill(dpar,dpar+N,-1);
	for(int i=0;i<N;++i){
		if(dpar[i]<0){
			dok[i]=true;
			dfs1(i);
		}
	}
	for(int i=0;i<N;++i){
		if(dpar[i]>=0){
			dch[dpar[i]].push_back(i);
			//cerr<<dpar[i]<<"<====="<<i<<endl;
		}
	}
	for(int j=0;j<M;++j){
		int ss=s[j],tt=t[j];
		if(dpar[ss]==tt){
			swap(ss,tt);
		}
		if(dpar[tt]!=ss){
			int from = (af[ss]<af[tt])?tt:ss;
			int to = (af[ss]<af[tt])?ss:tt;
			imos[from]++;
			imos[to]--;
		}
	}
	for(int i=0;i<N;++i){
		if(dok[i])
			dfs2(i);
	}
	set<pair<int,int>>bridge;
	for(int i=0;i<N;++i){
		if(!dok[i]&&imos[i]==0){
			bridge.insert({i,dpar[i]});
			DBG(i);
			DBG(dpar[i]);
		}
	}
	for(int j=0;j<M;++j){
		int nowc = bridge.count({s[j],t[j]}) + bridge.count({t[j],s[j]});
		nG[s[j]].push_back({t[j],nowc});
		nG[t[j]].push_back({s[j],nowc});
	}
	fill(id,id+N,-1);
	for(int i=0;i<N;++i){
		if(id[i]<0){
			dfs3(i,-1,i);
		}
	}
	for(int i=0;i<N;++i){
		idcnt[id[i]]++;
		DBG(id[i]);
	}
	for(auto p : bridge){
		DBG(p.first);
		DBG(p.second);
		int ss = id[p.first];
		int tt = id[p.second];
		pG[ss].push_back(tt);
		pG[tt].push_back(ss);
		DBG(ss);
		DBG(tt);
	}
	int ans = 0;
	memset(memo,0xff,sizeof(memo));
	for(int i=0;i<N;++i){
		if(dok[i]){
			ans += dp(id[i],-1);
		}
	}
	cout << ans << endl;
	return 0;
}
