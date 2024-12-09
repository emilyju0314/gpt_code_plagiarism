#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int LMAX=16;

int Damerau_Levenshtein(const char *s,const char *t,int INS=1,int DEL=1,int RPL=1,int SWP=1){
	int m=strlen(s),n=strlen(t);
	static int dp[LMAX+1][LMAX+1];

	rep(i,m+1) dp[i][0]=i*DEL;
	rep(j,n+1) dp[0][j]=j*INS;

	int s_last[128],t_last[128];
	memset(s_last,-1,sizeof s_last);
	rep(i,m){
		memset(t_last,-1,sizeof t_last);
		rep(j,n){
			int i1=s_last[t[j]],j1=t_last[s[i]];

			dp[i+1][j+1]=min(dp[i+1][j]+INS,dp[i][j+1]+DEL);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]?0:RPL));
			if(i1>=0 && j1>=0){
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i1][j1]+(i-i1-1)*DEL+SWP+(j-j1-1)*INS);
			}

			t_last[t[j]]=j;
		}
		s_last[s[i]]=i;
	}

	return dp[m][n];
}

int main(){
	for(int n,d;scanf("%d%d",&n,&d),n;){
		char s[200][20];
		rep(i,n) scanf("%s",s[i]);

		vector< pair<string,string> > ans;
		rep(i,n) rep(j,i) if(Damerau_Levenshtein(s[i],s[j])<=d) {
			if((string)s[i]<s[j]) ans.push_back(make_pair(s[i],s[j]));
			else                  ans.push_back(make_pair(s[j],s[i]));
		}
		sort(ans.begin(),ans.end());

		rep(i,ans.size()) printf("%s,%s\n",ans[i].first.c_str(),ans[i].second.c_str());
		printf("%d\n",ans.size());
	}

	return 0;
}