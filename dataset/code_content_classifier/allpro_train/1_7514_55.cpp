#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll A,B,inf = 1e9+7;

int main(){
	cin >> N >> A >> B;
	vector<ll> S(N+1,0),dp(N+1,0);
	if(A>B) swap(A,B);
	bool judge = true;
	for(int i=1;i<=N;i++){
		cin >> S[i];
		if(i>2 && S[i]-S[i-2]<A) judge = false;
	}
	S[0] = -1;
	if(!judge){
		cout << 0 << endl;
		return 0;
	}
	dp[0] = 1;
	int id = 0;//S[i]-S[i+1]<Aとなるi
	for(int i=1;i<=N;i++){
		(dp[i] += dp[i-1])%=inf;
		int s = lower_bound(S.begin(),S.end(),S[i]-B)-S.begin();
		if(S[i]-B>=0 && S[s]>S[i]-B) s--;
		if(s>=id){
			if(id>=1) (dp[i] += dp[s]-dp[id-1]+inf)%=inf;
			else (dp[i] += dp[s])%=inf;
		}
		if(S[i]-S[i-1]<A) id = i-1;
	}
	if(id>=1) cout << (dp[N]-dp[id-1]+inf)%inf << endl;
	else cout << dp[N] << endl;
}