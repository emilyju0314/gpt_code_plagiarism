#include <stdio.h>
#include <vector>
using namespace std;

int N,K;

int main()
{
	scanf ("%d %d",&K,&N);

	vector<int> ans;
	if (K == 1){
		N = (N + 1) / 2;
		for (int i=0;i<N;i++) ans.push_back(1);
	}
	else if (K % 2 == 0){
		ans.push_back(K/2);
		for (int i=1;i<N;i++) ans.push_back(K);
	}
	else{
		int D = N / 2;
		for (int i=1;i<=N;i++) ans.push_back((K+1)/2);
		while (D--){
			if (ans.back() == 1){
				if (ans.back() == 1) ans.pop_back();
			}
			else{
				ans.back()--;
				while (ans.size() < N) ans.push_back(K);
			}
		}
	}

	for (int i=0;i<ans.size();i++) printf ("%d%c",ans[i],i+1<ans.size()?' ':'\n');
	return 0;
}