#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string a,b;
vector<int> p[26],q[26][26],z[26][26][26],s,x;
void R(){
	string t;cin>>t;
	for(int i=0;i<t.size();i++)s.push_back(t[i]-'a');
	for(int i=0;i<t.size();i++){
		p[s[i]].push_back(i);
		if(i)q[s[i-1]][s[i]].push_back(i-1);
		if(i>1)z[s[i-2]][s[i-1]][s[i]].push_back(i-2);
	}
}
int Xd(){x.clear();
	for(int i=0;i<a.size();i++)x.push_back(a[i]-'a');
	if(x.size()==1)return p[x[0]].size()?p[x[0]][0]:-1;
	if(x.size()==2)return q[x[0]][x[1]].size()?q[x[0]][x[1]][0]+1:-1;
	if(x.size()==3)return z[x[0]][x[1]][x[2]].size()?z[x[0]][x[1]][x[2]][0]+2:-1;
	for(int i=0;i<z[x[0]][x[1]][x[2]].size();i++){
		int k=z[x[0]][x[1]][x[2]][i],w=x.size()-1;
		if(k+w<s.size()){
			bool o=1;
			for(int j=k+3;j<=k+w;j++)if(s[j]!=x[j-k])o=0;
			if(o)return k+w;
		}
	}return -1;
}
int Yd(){x.clear();
	for(int i=0;i<b.size();i++)x.push_back(b[i]-'a');
	if(x.size()==1)return p[x[0]].size()?p[x[0]][p[x[0]].size()-1]:-1;
	if(x.size()==2)return q[x[0]][x[1]].size()?q[x[0]][x[1]][q[x[0]][x[1]].size()-1]:-1;
	if(x.size()==3)return z[x[0]][x[1]][x[2]].size()?z[x[0]][x[1]][x[2]][z[x[0]][x[1]][x[2]].size()-1]:-1;
	for(int i=z[x[0]][x[1]][x[2]].size()-1;i>=0;i--){
		int k=z[x[0]][x[1]][x[2]][i],w=x.size()-1;
		if(k+w<s.size()){
			bool o=1;
			for(int j=k+3;j<=k+w;j++)if(s[j]!=x[j-k])o=0;
			if(o)return k;
		}
	}return -1;
}
int main(){
	R();int m;cin>>m;
	while(m--){
		cin>>a>>b;int l=Xd(),r=Yd();
		if(r!=-1&&l!=-1&&r>=l-a.size()+1&&l+1<=r+b.size())cout<<r-l+b.size()+a.size()-1<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}