#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<functional>
#define all(c) c.begin(),c.end()
#define uni(c) c.erase(unique(c.begin(),c.end()),c.end())
#define pb push_back
using namespace std;
vector<int> uf;
int sum=0;
int n,m,ans;
string s;
int cal(int x){
	return x%10+x/10;
}
void f(int a,int b,int cnt){
	//cout<<a<<"  "<<b<<endl;
	if(a){
		for(int i=0;i<uf.size();i++)
			f(a-1,b,cnt+uf[i]);
	}else if(b){
		for(int i=0;i<uf.size();i++)
			f(a,b-1,cnt+cal(uf[i]*2));
	}else{
		ans+=((cnt+sum)%10==0);
	}
	
}
int main(){
	while(cin>>n>>s>>m){
		uf.resize(m);
		for(int i=0;i<m;i++){
			cin>>uf[i];
		}
		sum=0;
		int a=0,b=0;
		for(int i=1;i<=n;i++){
			if(i&1){
				if(isdigit(s[s.size()-i])){
					sum+=s[s.size()-i]-'0';
				}else{
					a++;
				}
			}else{
				if(isdigit(s[s.size()-i])){
					sum+=cal(2*(s[s.size()-i]-'0'));
				}else{
					b++;
				}
			}
			
		}
		ans=0;
		f(a,b,0);
		cout<<ans<<endl;
	}
	return 0;
}