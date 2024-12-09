#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

char buff[100001];
int mex(char a, char b){
	for(char i = 'a';;i ++){
		if(i==a or i==b)
			continue;
		return i;
	}
}
int main(){
	int t=1;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vector <int> weights(n);
		long long sum=0ll;
		for(int i = 0;i < n;i ++){
			scanf("%d", &weights[i]);
			sum+=weights[i];
		}
		vector <vector <int> > adjLis(n);
		for(int i = 0;i < n-1;i ++){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;v--;
			adjLis[u].push_back(v);
			adjLis[v].push_back(u);
		}
		vector <int> aaaaaaa;
		for(int i = 0;i < n;i ++){
			for(int j = adjLis[i].size()-1;j --;){
				aaaaaaa.push_back(weights[i]);
			}
		}
		sort(aaaaaaa.begin(), aaaaaaa.end());
		printf("%lld", sum);
		while(!aaaaaaa.empty()){
			sum+=aaaaaaa.back();
			aaaaaaa.pop_back();
			printf(" %lld", sum);
		}
		printf("\n");
	}
}