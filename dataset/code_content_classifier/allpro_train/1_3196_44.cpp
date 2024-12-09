#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int main(){
	int n,k,t,u,v,l;
	cin>>n>>k>>t>>u>>v>>l;
	vector<bool>d(10010,false);
	rep(i,n){
		int a;
		cin>>a;
		d[a]=true;
	}
	double sum=0;
	int T=0;
	int hav=0;
	rep(i,l){
		if(d[i]){
			sum+=1./v;
			if(hav==k){
				T=t*v-1;
			}else if(T){
				T--;
				hav++;
			}else{
				T=t*v-1;
			}
		}else{
			if(T){
				T--;
				sum+=1./v;
			}else if(hav){
				hav--;
				T+=t*v-1;
				sum+=1./v;
			}else sum+=1./u;
			
		}
	}
	printf("%.8f\n",sum);
}