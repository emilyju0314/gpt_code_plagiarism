#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main(void){
	int R0,W0,C,R;
	while(cin >> R0 >> W0 >> C >> R,R0){
		rep(ans,100000){
			if(R0+ans*R >= C*W0){
				cout << ans << endl;
				break;
			}
		}
	}
	return 0;
}