#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long int;
  
int ssum[100],tsum[100];
map<int,int> sprod[100],tprod[100];
vector<int> tint;
  
const int nmax=10000010;
int sum[nmax];
ll prod[nmax];

int main(void){
    string d;
    cin >> d;
    int n=d.size();
    int s=n/2,t=n-s;
    
    ll ns=1,nt=1;
    rep(loop,s) ns*=10;
    rep(loop,t) nt*=10;

    int d_sum=0,dt_sum=0;
   	ll  d_prod=1LL,dt_prod=1LL;

    rep(i,n){
        int cur=d[i]-'0';
        d_sum+=cur;
        d_prod*=(cur+1);
    }

    rep(i,t){
        int cur=d[i+s]-'0';
        dt_sum+=cur;
        dt_prod*=(cur+1);
    }
 	

    rep(i,nt){
        int cur=i;
        sum[i]=0; 
        prod[i]=1LL;
        rep(j,t){
            int dd=cur%10;
            sum[i]+=dd;
            prod[i]*=(dd+1);
            cur/=10;
        }    
    }

    rep(i,nt){ 
        tsum[sum[i]]++;
        tprod[sum[i]][prod[i]]++;
        if(dt_sum==sum[i]&&dt_prod==prod[i]) tint.emplace_back(i);
    }
  	

    ll ans=0LL;
    int ds=0,dt=0;
    rep(i,s) ds=10*ds+d[i]-'0';
    rep(i,t) dt=10*dt+d[s+i]-'0';
  	
	if(ns!=nt) 
		rep(i,ns) ssum[sum[i]]++,sprod[sum[i]][prod[i]]++;
	else
		rep(i,100) ssum[i]=tsum[i],sprod[i]=tprod[i];
    rep(i,ds) if(d_sum-sum[i]>=0&&d_prod>=prod[i]&&d_prod%prod[i]==0) ans+=1LL*tprod[d_sum-sum[i]][d_prod/prod[i]];

    
    rep(i,9*s+1)rep(j,9*t+1){
    	if(i+j>d_sum) break;
    	if(i+j<d_sum) 
    		ans+=1LL*ssum[i]*tsum[j];
    	else{
    		for(auto &k:sprod[i]){
    			for(auto &l:tprod[j]){
  	      			if(1LL*k.first*l.first<d_prod) 
  	      				ans+=1LL*k.second*l.second;
  	      		} 
        	}
    	}
    }
	
    sort(tint.begin(),tint.end());
    ll idx=lower_bound(tint.begin(),tint.end(),dt)-tint.begin();
    ans+=idx;
    cout << ans << endl;
    return 0;
}