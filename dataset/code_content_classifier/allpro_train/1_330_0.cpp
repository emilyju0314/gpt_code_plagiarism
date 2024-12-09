#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct uftree{
	int par[25];
	int rank[25];
	uftree(){
	}
	void init(int n){
		for(int i=0;i<n;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}

	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y)return;
		if(rank[x]<rank[y]){
			par[x]=y;
		}else{
			if(rank[x]==rank[y])rank[x]++;
			par[y]=x;
		}
	}

	bool same(int x,int y){
		return find(x)==find(y);
	}
};


int h,w,n,R;
vector<int> vec;

int tmp[8];
int ki[8];
int id[1<<25];

void dfs(int x,int c){
	if(x==w){
		int val=0;
		for(int i=0;i<w;i++){
			val+=tmp[i]*ki[i];
		}
		vec.push_back(val);
	}else{
		if(x==0){
			tmp[0]=0;
			dfs(x+1,0);
			tmp[0]=1;
			dfs(x+1,1);
		}else{
			if(tmp[x-1]==0){
				tmp[x]=c+1;
				dfs(x+1,c+1);
			}
			for(int i=0;i<=c;i++){
				tmp[x]=i;
				dfs(x+1,c);
			}
		}
	}
}

int dp[10][100000][2];

void init(){
	ki[0]=1;
	for(int i=1;i<w;i++){
		ki[i]=ki[i-1]*5;
	}
	dfs(0,0);
	sort(vec.begin(),vec.end());
	memset(id,-1,sizeof(id));
	for(int i=0;i<vec.size();i++){
		id[vec[i]]=i;
	}
}

int fie[8][8];
int val[64];
int sx,sy;

int is_person(int r){
	if(sy!=r)return 0;
	for(int i=0;i<w;i++){
		if(tmp[i]>=1 && sx==i)return 1;
	}
	return 0;
}

int calc_rock(int r){
	int sum=0;
	for(int i=0;i<w;i++){
		if(tmp[i]>=1 && fie[r][i]==-1)return -1;
		if(tmp[i]>=1 && fie[r][i]==-2)sum+=R;
	}
	return sum;
}

int calc_item(int r){
	int sum=0;
	for(int i=0;i<w;i++){
		if(tmp[i]>=1 && fie[r][i]>=1){
			sum+=val[fie[r][i]];
		}
	}
	return sum;
}

int calc_id(){
	int val=0;
	for(int i=0;i<w;i++){
		val+=tmp[i]*ki[i];
	}
	if(id[val]==-1){
		for(int i=0;i<w;i++){
			printf("%d ",tmp[i]);
		}
		printf("\n");
	}
	//assert(id[val]!=-1);
	return id[val];
}

void calc_row0(int r,int bit){
	int sz=0;
	for(int i=0;i<w;i++){
		if((bit>>i)&1){
			if(i==0){
				sz++;
				tmp[i]=sz;
			}else{
				if(tmp[i-1]!=0){
					tmp[i]=tmp[i-1];
				}else{
					sz++;
					tmp[i]=sz;
				}
			}
		}else{
			tmp[i]=0;
		}
	}
	int cost_r=calc_rock(r);
	if(cost_r==-1)return;
	int flag=is_person(r);
	int cost_i=calc_item(r);
	int index=calc_id();
	dp[r+1][index][flag]=cost_i-cost_r;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool fl1[5];
bool fl2[5];
int tmp2[2][8];
int tmp3[2][8];
int colo[8];
stack<int> st;
bool po;
uftree uf;

void dfs_row(int x,int y,int sz){
	tmp3[y][x]=sz;
	if(y==0){
		if(tmp2[y][x]>0){
			uf.unite(tmp2[y][x],sz);
		}
		st.push(tmp2[y][x]);
	}else{
		po=true;
	}
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && nx<w && ny>=0 && ny<2){
			if(tmp2[ny][nx]!=0 && tmp3[ny][nx]==0){
				dfs_row(nx,ny,sz);
			}
		}
	}
}

void calc(int r,int index_p,int flag_p,int bit){
	memset(tmp2,0,sizeof(tmp2));
	{
		int v=vec[index_p];
		int x=0;
		while(v>0){
			if(v%5>=1)tmp2[0][x]=v%5;
			else{
				tmp2[0][x]=0;
			}
			v/=5;
			x++;
		}
	}
	for(int i=0;i<w;i++){
		if((bit>>i)&1){
			tmp2[1][i]=1;
		}
	}
	memset(fl1,false,sizeof(fl1));
	memset(fl2,false,sizeof(fl2));
	memset(tmp3,0,sizeof(tmp3));
	uf.init(6);
	for(int i=0;i<w;i++){
		if(tmp2[0][i]!=0 && tmp3[0][i]==0){
			while(st.size())st.pop();
			po=false;
			dfs_row(i,0,tmp2[0][i]);
			if(po){
				while(st.size()){
					int v=st.top();
					st.pop();
					fl2[v]=true;
				}
			}
		}
	}
	int cn=0;
	int cn2=0;
	{
		for(int i=0;i<w;i++){
			if(tmp2[0][i]>0){
				fl1[tmp2[0][i]]=true;
			}
		}
		for(int i=1;i<=4;i++){
			if(fl1[i])cn++;
			if(fl2[i])cn2++;
		}
		if(cn>=2){
			for(int i=1;i<=4;i++){
				if(fl1[i] && !fl2[i])return;
			}
		}
	}
	if(cn2>0){
		int prev=-2;
		int kero=-100;
		for(int i=0;i<w;i++){
			if(tmp3[1][i]==0 && tmp2[1][i]==1){
				if(prev+1==i){
					tmp3[1][i]=kero;
				}else{
					tmp3[1][i]=++kero;
				}
				prev=i;
			}
		}
	}else{
		for(int i=0;i<w;i++){
			if(tmp3[1][i]==0 && tmp2[1][i]==1){
				return;
			}
		}
	}
	{
		for(int i=0;i<w;i++){
			if(tmp3[1][i]>0){
				tmp3[1][i]=uf.find(tmp3[1][i]);
			}
		}
	}
	{
		vector<int> vt;
		for(int i=0;i<w;i++){
			tmp[i]=tmp3[1][i];
			if(tmp[i]!=0)vt.push_back(tmp[i]);
		}
		vt.push_back(-105);
		sort(vt.begin(),vt.end());
		vt.erase(unique(vt.begin(),vt.end()),vt.end());
		for(int i=0;i<w;i++){
			if(tmp[i]==0)continue;
			tmp[i]=lower_bound(vt.begin(),vt.end(),tmp[i])-vt.begin();
		}
		map<int,int> mp;
		for(int i=0;i<w;i++){
			if(tmp[i]==0)continue;
			if(mp.find(tmp[i])==mp.end()){
				mp[tmp[i]]=mp.size();
			}
		}
		for(int i=0;i<w;i++){
			if(tmp[i]==0)continue;
			tmp[i]=mp[tmp[i]];
		}
	}
	
	int cost_r=calc_rock(r);
	if(cost_r==-1)return;
	int flag=is_person(r)|flag_p;
	int cost_i=calc_item(r);
	int index=calc_id();
	dp[r+1][index][flag]=max(dp[r+1][index][flag],dp[r][index_p][flag_p]+cost_i-cost_r);
	if(dp[r][index_p][flag_p]+cost_i-cost_r>=0){
		/*
		printf("r=%d %d %d-> index=%d flag=%d cost=%d\n",r,index_p,flag_p,index,flag,dp[r][index_p][flag_p]+cost_i-cost_r);
		for(int i=0;i<2;i++){
			for(int j=0;j<w;j++){
				printf("%d ",tmp2[i][j]);
			}
			printf("\n");	
		}
		for(int j=0;j<w;j++){
			printf("%d ",tmp[j]);
		}
		printf("\n");
		*/
	}
}

bool is_ok(int v){
	while(v>0){
		if(v%5>=2)return false;
		v/=5;
	}
	return true;
}

int main(void){
	scanf("%d%d%d%d",&h,&w,&n,&R);
	init();
	for(int i=0;i<h;i++){
		string s;
		cin >> s;
		for(int j=0;j<w;j++){
			if(s[j]>='0' && s[j]<='9'){
				fie[i][j]=(s[j]-'0')+1;
			}
			if(s[j]>='a' && s[j]<='z'){
				fie[i][j]=(s[j]-'a')+11;
			}
			if(s[j]>='A' && s[j]<='Z'){
				fie[i][j]=(s[j]-'A')+37;
			}
			if(s[j]=='@'){
				sx=j;
				sy=i;
			}
			if(s[j]=='#'){
				fie[i][j]=-1;
			}
			if(s[j]=='*'){
				fie[i][j]=-2;
			}
		}
	}
	for(int i=0;i<n;i++){
		char c;
		int a;
		scanf(" %c%d",&c,&a);
		if(c>='0' && c<='9'){
			val[(c-'0')+1]=a;
		}
		if(c>='a' && c<='z'){
			val[(c-'a')+11]=a;
		}
		if(c>='A' && c<='Z'){
			val[(c-'A')+37]=a;
		}
	}
	for(int i=0;i<=h;i++){
		for(int j=0;j<vec.size();j++){
			for(int k=0;k<2;k++){
				dp[i][j][k]=-INF;
			}
		}
	}
	for(int j=0;j<h;j++){
		for(int i=0;i<(1<<w);i++){
			calc_row0(j,i);
		}
	}
	for(int i=1;i<h;i++){
		for(int j=1;j<vec.size();j++){
			for(int k=0;k<2;k++){
				if(dp[i][j][k]==-INF)continue;
				for(int l=0;l<(1<<w);l++){
					calc(i,j,k,l);
				}
			}
		}
	}
	int ans=0;
	for(int j=1;j<=h;j++){
		for(int i=0;i<vec.size();i++){
			if(is_ok(vec[i])){
				ans=max(ans,dp[j][i][1]);
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}

