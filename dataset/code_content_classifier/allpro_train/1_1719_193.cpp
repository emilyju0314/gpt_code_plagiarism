#include<iostream>
using namespace std;
int main(){
	int a, b, N, s[1000] = {}, f[1000] = {},co=0;
	cin >> a >> b >> N;
	for (int i = 0; i < N; i++){
		cin >> s[i] >> f[i];
		if (s[i]<=a&&b<=f[i]){
			co++;
		}
		else if (a<=s[i]&&s[i]<b){
			co++;
		}
		else if (a<f[i] && f[i] <= b){
			co++;
		}
		else if (a < s[i] && f[i]<b){
			co++;
		}
	}
	if (co>0){
		co = 1;
	}
	cout << co << endl;
	return 0;
}