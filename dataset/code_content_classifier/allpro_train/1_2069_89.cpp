#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(string s;cin>>s && s!="#";){
		int n=s.size();
		
		vector<string> res;
		string t=s;
		array<char,26> first;
		for(int i=0;i<(1<<n);i++){
			bool ok=true;
			for(int j=0;j<n;j++) if(i>>j&1) ok&=s[j]!='z';
			if(!ok) continue;
			
			for(int j=0;j<n;j++) t[j]=s[j]+(i>>j&1);
			first.fill(-1);
			for(int j=s.size();j--;) first[t[j]-'a']=j;
			for(int j=1;j<26;j++) if(first[j]!=-1) t[first[j]]--;
			
			if(t==s){
				for(int j=0;j<n;j++) t[j]=s[j]+(i>>j&1);
				res.push_back(t);
			}
		}
		sort(begin(res),end(res));
		
		cout<<res.size()<<endl;
		if(res.size()>10) res.erase(begin(res)+5,end(res)-5);
		for(string t:res) cout<<t<<endl;
	}
}