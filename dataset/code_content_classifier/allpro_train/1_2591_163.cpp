#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
	int m,n,l;
			while(cin >> m >> n >> l && !(m==0 && n==0 && l==0))
			{
					vector<int> p(m);
					for(int i=0;i<m;i++)
							cin >> p[i];

					sort(p.rbegin(), p.rend());
					int ans = 0, sum = 0;;

					for(int i=n;i<=l;i++)
					{
							if(sum <= p[i-1]-p[i])
							{
								ans = i;
								sum = p[i-1] - p[i];
							}
					}
					cout << ans << endl;
			}
}
