#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <functional>
#include <iomanip>
//#include <windows.h>  //Should be deleted when using AtCoder&POJ
using namespace std;

#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)
/**==Info==
*Program:1
*Problem:Mancala
*Date:2019-7-3
*Algorithm:DP
*Stats:Unknown*/

bool debug=false;

int n,k;
const int mx=10000;
ll dp[105][mx];

const ll mod=1e9+7;
const ll inv2=5e8+4;

ll qp(ll a,ll b){
	if(b==0){
		return 1;
	}
	ll ans=qp(a,b/2);
	if(b%2){
		return ans*ans%mod*a%mod;
	}else{
		return ans*ans%mod;
	}
}

int main(int argc,char* argv[]){
	qi;
	cin>>n>>k;
	
	dp[n+1][0]=1;
	
//	cout<<"D"<<endl;
	
	for(int i=n;i>=1;i--){
		for(int j=0;j<mx;j++){
			for(int l=0;l<=k;l++){
//				cout<<i<<" "<<j<<" "<<l<<endl;
				
				/*
				Please, don't forget to module the answer				
				
				=====
				p71.cpp:72:23: runtime error: signed integer overflow: 6795705775047932304 + 3397852887523966152 cannot be represented in type 'long long'
				SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior p71.cpp:72:23 in 
				
				Runtime error: exit code is 1
				=====
				Used: 124 ms, 10600 KB
*/
				if(l<=i){
					//ok
					if(j+(l+j)/i<mx){
						dp[i][j+(l+j)/i]+=dp[i+1][j];
						dp[i][j+(l+j)/i]%=mod;
					}
					
				}else{
					//already (bomb)ed
					dp[i][j]+=dp[i+1][j];
					dp[i][j]%=mod;
				}
			}
		}
	}
	
//	cout<<"BBB"<<endl;
	
	ll killed=0;
	for(int i=0;i<mx;i++){
		killed+=1ll*i*dp[1][i]%mod;
		killed%=mod;
	}
//	cout<<killed<<endl;
	
	//(k+1)^(n-1)*sm*n
	ll tot=qp(k+1,n-1)*k%mod*(k+1)%mod*inv2%mod*n%mod;
	
//	cout<<tot<<endl;
	
	cout<<(tot-killed+mod)%mod<<endl;
	return 0;
}

