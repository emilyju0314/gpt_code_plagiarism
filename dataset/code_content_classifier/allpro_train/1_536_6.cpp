/*input 




*/

#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
int fin(int x,int par[]){
	return (x==par[x])? x: par[x]=fin(par[x],par); 
}
void uni(int u,int v,int par[]){
	int parx = fin(u,par); 
	int pary = fin(v,par); 
	par[parx]=pary;
	return ;
}
int main()
{
    int t; 
    cin>>t; 
    while(t--){
    	int n,m,k; 
    	cin>>n>>m>>k; 
    	vector<pair<ll int,pair<int,int>>> ans; 
    	for(int i=0;i<m; ++i){
    		int x,y;
    		ll w;  
    		cin>>x>>y>>w;
    		ans.push_back({w,{x,y}}); 
    	}
    	sort(ans.begin(),ans.end()); 
    	int count=0; 
    	int par[n+1]; 
    	ll int sum=0; 
    	for(int i=0;i<=n; ++i)par[i]=i;
    	bool find = false; 
    	int lastEdge =0; 
    	int i; 
    	// cout<<"he"; 
    	for(i=0;i<m && count<(n-1); ++i){

    		auto x = ans[i]; 
    		// cout<<x.first<<" " ; 
    		int u = x.second.first, v = x.second.second; 
    		// cout<<u<<" "<<v<<" "; 
    		if(fin(u,par)==fin(v,par))continue; 
    		else { 
    			// cout<<x.first<<" "; 
    			if(x.first >= k){
    				sum+=(x.first-k); 
    				find=true; 
    			}
    			lastEdge=x.first; 	
	   		}
    		uni(u,v,par);
    		++count; 
    	}
    	if(!find){
    		sum = (k-lastEdge); 
    		for(;i<m; ++i){
    			sum = min(sum,abs(ans[i].first-k)); 
    		}
    	}
    	cout<<sum<<endl; 
    }
    
	return 0; 
}