#include <iostream>
using namespace std;
#define rep2(x,from,to) for(int x=(from);x<(to);++(x))
#define rep(x,to) rep2(x,0,to)
int main(){
	int n, a[110], t;
	while(cin >> n, n) {
		rep(i,n) {
			cin >> a[i];
		}
		cin >> t;
		int lo = 0, hi = n-1, cnt = 0, mid = -1;
		while(hi >= lo) {
			mid = (hi+lo) / 2;
			cnt++;
			if(a[mid]==t) break;
			else if(a[mid]<t) lo = mid+1;
			else hi = mid-1;
		}
		cout << cnt << endl;
	}
	return 0;
}