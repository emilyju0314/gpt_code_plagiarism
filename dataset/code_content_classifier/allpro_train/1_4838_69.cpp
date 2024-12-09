#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,a,n) for(int i=a; i<(n); i++)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){

	int m,t,p,r;
	while( cin >> m >> t >> p >> r, m|t|p|r ){
		int sumtime[t+1];
		int ac[t+1];
		int wrong[t+1][p+1];
		int num[t+1];

		rep(i,t+1){
			rep(j,p+1){
				wrong[i][j] = 0;
			}
			ac[i]=0;
			sumtime[i] = 0;
			num[i] = i;
		}
		rep(k,r){
			int tmpm,tmpt,tmpp,tmpj;
			cin >> tmpm >> tmpt >> tmpp >> tmpj;
			if(tmpj) wrong[tmpt][tmpp]++;
			else{
				sumtime[tmpt] += tmpm + wrong[tmpt][tmpp] * 20;
				ac[tmpt] ++;
			}
		}
//		rep(i,t) cout << "ac=" <<ac[i] << endl;
		for(int i = 1; i < t;i++){
//		reps(i,1,t-1){
			for(int j = i+1; j <= t;j++){
	//		reps(j,i+1;t){
				if(ac[i] < ac[j] || (ac[i]==ac[j] && sumtime[i]> sumtime[j]) ||
				 (ac[i]==ac[j] && sumtime[i] == sumtime[j] && num[i] < num[j])){
					swap(ac[i],ac[j]);
					swap(sumtime[i],sumtime[j]);
					swap(num[i],num[j]);
				}
			}
		}
		for(int i = 1; i < t;i++){
//		reps(i,1,t-1){
			if(ac[i] == ac[i+1] && sumtime[i] == sumtime[i+1]){
				cout << num[i] << "=";
			}
			else{
				cout << num[i] << ",";
			}
		}
		cout << num[t] << endl;

	}
	return 0;
}