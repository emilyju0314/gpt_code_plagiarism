#include<cstdio>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
char word[20][21];
vector<int> L[21]; // L[l] := ( 長さ l の単語の集合 )

char s[128];
vector<int> pos,len; // 空白で区切った s の部分文字列の開始位置と長さ

int dup;
char f[128],f_ans[128]; // アルファベットの対応表

bool used[80]; // s の部分文字列 i をすでに調べたかどうか
bool dfs(){
	if(dup>=2) return false;

	// 絶対に埋められない部分文字列が出てきたら探索打ち切り
	rep(i,pos.size()) if(!used[i]) {
		int m=len[i];
		const char *t=s+pos[i];
		bool ok=false;
		rep(j,L[m].size()){
			const char *w=word[L[m][j]];

			bool b=true;
			rep(k,m){
				char c1=t[k],c2=w[k];
				if(f[c1]!='?' && f[c2]!='?'){
					if(c2!=f[c1]) b=false;
				}
				else if(f[c1]=='?' && f[c2]=='?'){}
				else{
					b=false;
				}
			}
			if(b){ ok=true; break; }
		}
		if(!ok) return false;
	}

	int i0=-1;
	rep(i,len.size()) if(!used[i]) {
		if(i0==-1 || len[i0]<len[i]) i0=i;
	}
	if(i0==-1){
		dup++;
		if(dup>=2) return false;
		memcpy(f_ans,f,sizeof f);
		return true;
	}

	int m=len[i0];
	const char *t=s+pos[i0];
	char tmp[128];
	rep(i,L[m].size()){
		const char *w=word[L[m][i]]; // 部分文字列 t に単語 w を割り当てる

		bool ok=true; // その割り当てで矛盾が起こらないか
		memcpy(tmp,f,sizeof f);
		rep(j,m){
			char c1=t[j],c2=w[j];
			if(f[c1]!='?' && f[c2]!='?'){
				if(c2!=f[c1]) ok=false;
			}
			else if(f[c1]=='?' && f[c2]=='?'){
				f[c1]=c2;
				f[c2]=c1;
			}
			else{
				ok=false;
			}
		}

		if(ok){
			used[i0]=true;
			dfs();
			used[i0]=false;
		}

		memcpy(f,tmp,sizeof f);
	}

	return dup==1;
}

int main(){
	for(;scanf("%d",&n),n;){
		rep(i,n) scanf("%s ",word[i]);
		rep(l,21) L[l].clear();
		rep(i,n) L[strlen(word[i])].push_back(i);

		fgets(s,128,stdin);
		pos.clear();
		len.clear();
		for(int i=0,pre=0;;i++){
			if(s[i]=='.' || s[i]==' '){
				pos.push_back(pre);
				len.push_back(i-pre);
				pre=i+1;
				if(s[i]=='.') break;
			}
		}

		for(char c='A';c<='Z';c++) f[c]='?';

		dup=0;
		rep(i,pos.size()) used[i]=false;
		if(!dfs()) puts("-.");
		else{
			rep(i,pos.size()){
				rep(j,len[i]) putchar(f_ans[s[pos[i]+j]]);
				putchar(i<(int)pos.size()-1?' ':'.');
			}
			puts("");
		}
	}

	return 0;
}