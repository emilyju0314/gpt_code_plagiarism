// O(NH+N^2) using rolling hash


   #include <bits/stdc++.h>
 #define int long long
 #define inf  1000000007
 #define pa pair<int,int>
  #define  mp make_pair
  #define  pb push_back
  #define ll long long
using namespace std;

int beki(int wa,int rr,int warukazu){                	
	if(rr==0) return 1%warukazu;
	if(rr==1) return wa%warukazu;
	wa%=warukazu;
	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
	ll zx=beki(wa,rr/2,warukazu);
	return (zx*zx)%warukazu;
}
                
struct roll_hash{
private:
public:
	
	string str;
	
	vector<int> r1,r2;
	int MOD1=inf;
	int MOD2=inf+2;
	int base=12341;
	vector<int> baseinv1;
	vector<int> baseinv2;
	
	void make_hash(string s){
		this->str=" "+s;
		int l=s.length();
		r1.resize(l+1);
		r2.resize(l+1);
		baseinv1.resize(l+1);
		baseinv2.resize(l+1);
		
		r1[0]=0;
		r2[0]=0;
		int kake1=1;
		int kake2=1;
		for(int i=1;i<=l;i++){
			r1[i]=r1[i-1]+kake1*(str[i]-'A');
			r2[i]=r2[i-1]+kake2*(str[i]-'A');
			r1[i]%=MOD1;
			r2[i]%=MOD2;
			
			kake1=base*kake1%MOD1;
			kake2=base*kake2%MOD2;
		}
		
		baseinv1[l]=beki(beki(base,l,MOD1),MOD1-2,MOD1);
		baseinv2[l]=beki(beki(base,l,MOD2),MOD2-2,MOD2);
		
		for(int i=l-1;i>=0;i--){
			baseinv1[i]=baseinv1[i+1]*base%MOD1;
			baseinv2[i]=baseinv2[i+1]*base%MOD2;
		}
	}
	
	pa hash(int l,int r){//[l,r)
		int z1=(r1[r]+MOD1-r1[l])%MOD1;
		z1*=baseinv1[l];
		z1%=MOD1;
	return mp(z1,0);
		int z2=(r2[r]+MOD2-r2[l])%MOD2;
		z2*=baseinv2[l];
		z2%=MOD2;
	return mp(z1,z2);
	}
	
	bool same(int l1,int r1,int l2,int r2){
		if(l1-r1!=l2-r2)return 0;
	
		return hash(l1,r1)==hash(l2,r2);
	}
	
	
};

int vis[4100];
vector<pa> mae[26];
vector<pa> dp[4100];
vector<int> aite;
vector<int> kei;
vector<pa> uni;
	
vector<pa> mer(vector<pa> &v1,vector<pa> &v2){
	int n=v1.size();
	
	vector<pa> v3;
	
	for(int i=0;i<n;i++){
		v3.pb({v2[v1[i].first].first,v1[i].second+v2[v1[i].first].second});
	}
	return v3;
}
vector<pa> be(vector<pa> v1,int k){
	if(k==1) return v1;
	if(k%2) {
		vector<pa>ww=be(v1,k-1);
		return mer(ww,v1);
	}
	vector<pa> w=be(v1,k/2);
	return mer(w,w);
}

	
void dfs(int r){
	if(vis[r])return;
	vis[r]=1;
	int owari=aite[r];
	int it=r+1;
	dp[r]=uni;
	
	while(it<owari){
		
		if(aite[it]==-1){
			it++;
			continue;
		}
		if(vis[it]==0){
			dfs(it);
			
		}
		
		dp[r]=mer(dp[r],dp[it]);
		it=aite[it]+1;
	}
	
	dp[r]=be(dp[r],kei[r]);

	return;
}

int solve(){
	string h,n;
	cin>>h;
	if(h=="#")exit(0);
	cin>>n;
	h="1("+h+")";
	for(int i=0;i<4100;i++)vis[i]=0;

	aite.clear();
	aite.resize(4100,-1);
	kei.resize(4100,-1);
	string s="";
	int l=h.length();
	int it=0;
	stack<int> st;
	while(1){
		if(it==l)break;
		if(h[it]>='0' && h[it]<='9'){
			int val=0;
			while(h[it]>='0' && h[it]<='9'){
				val*=10;
				val+=h[it]-'0';
				it++;
			}
			if(h[it]=='('){
				st.push(s.length());
				kei[s.length()]=val;
				s+='(';
				it++;
			}
			else{
				aite[s.length()]=s.length()+2;
				kei[s.length()]=val;
				s+='(';
				s+=h[it];
				s+=')';
				it++;
				
			}
			
			continue;
		}
		
		if(h[it]==')'){
			int z=st.top();
			st.pop();
			aite[z]=s.length();
			s+=")";
		it++;
		continue;
		}
		if(h[it]>='A' && h[it]<='Z'){
			s+=h[it];
			it++;
		}
		
	}
	roll_hash rh;
	rh.make_hash(n);
	
	int g=s.length();
	
	uni.clear();
	for(int i=0;i<=n.length();i++)uni.pb({i,0});
	for(int i=0;i<s.length();i++)dp[i]=uni;		
	for(int i=0;i<26;i++){
		mae[i].clear();
		mae[i].resize(n.length()+1);
	}
	for(int i=0;i<n.length();i++){
	
		for(int j=0;j<26;j++)mae[j][i]={n.length(),0};
	
	for(int j=0;j<=i+1;j++){
		// compare[0,j),[i-j+1,i+1)
		if(j==n.length()) continue;
		
			if(rh.same(0,j,i-j+1,i+1)){

			if(j==n.length()-1)mae[n[j]-'A'][i]={j,1};
			else mae[n[j]-'A'][i]={j,0};
		}
	}
}
for(int i=0;i<26;i++){
	if(n[0]-'A'==i){
		if(n.length()==1) mae[i][n.length()]={0,1};
		else mae[i][n.length()]={0,0};
	}
	else{
			mae[i][n.length()]={n.length(),0};
	}
}

	for(int i=0;i<s.length();i++)if(s[i]>='A'&&s[i]<='Z'){
		aite[i]=i;
		int c=s[i]-'A';		
		dp[i]=mae[c];
		vis[i]=1;
	}
	dfs(0);
	return dp[0].back().second;
}


 signed main(){
 	
 
   	cin.tie(0);
   	ios::sync_with_stdio(false);
 	while(1){
 		cout<<solve()<<endl;
 	}
	
 	return 0;
 
  }
 
