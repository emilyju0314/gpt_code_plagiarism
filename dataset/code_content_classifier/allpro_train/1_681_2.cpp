#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

bool tri_valid(int a, int b, int c) {
	vector<int>v{ a,b,c };
	sort(v.begin(),v.end());
	return v[2]<v[0]+v[1];
}

ld get_theta(ld a1, ld a2, ld x) {
	return (a1*a1+a2*a2-x*x)/(2*a1*a2);
}

int main() {
	cout<<setprecision(10)<<fixed;
	while (true){
		int N;cin>>N;
		if(!N)break;
		vector<int>sticks(N);
		for(int i=0;i<N;++i)cin>>sticks[i];

		vector<int>av(6);
		ld ans=0;
		for (av[0] = 0; av[0] < N; ++av[0]) {
			for ( av[1] = av[0]+1; av[1] < N; ++av[1]) {
				for ( av[2] = av[1]+1; av[2] < N; ++av[2]) {
					for (av[3] = 0; av[3] < N; ++av[3]) {
						for ( av[4] = 0; av[4] < N; ++av[4]) {
							for ( av[5] = 0; av[5] < N; ++av[5]) {
								bool ok=true;
								for (int i = 0; i < 6; ++i) {
									for (int j = i + 1; j < 6; ++j) {
										if(av[i]==av[j])ok=false;
									}
								}
								if(!ok)continue;
								vector<int>v(6);
								for(int i=0;i<6;++i)v[i]=sticks[av[i]];
								if(!tri_valid(v[0],v[1],v[2]))ok=false;
								for (int i = 0; i < 3; ++i) {
									if(!tri_valid(v[i],v[3+(i+1)%3],v[3+(i+2)%3]))ok=false;
								}
								if(!ok)continue;

								vector<ld>thetas(3);
								for (int i = 0; i < 3; ++i) {
									thetas[i]=get_theta(v[3+(i+1)%3],v[3+(i+2)%3],v[i]);
								}

								ld num=1+2*thetas[0]*thetas[1]*thetas[2]-(pow(thetas[0],2)+pow(thetas[1],2)+pow(thetas[2],2));
								if (num > 0) {
									ans=max(ans,v[3]*v[4]*v[5]*sqrt(num)/6.0);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
