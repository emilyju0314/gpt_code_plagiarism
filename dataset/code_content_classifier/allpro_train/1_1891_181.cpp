#include <cstdio>
#include <algorithm>
using namespace std;
#define MP make_pair
int main(){
	int n;
	for(;;){
		scanf("%d\n",&n);
		if(n==0) break;
		pair<pair<int,int>,pair<int,char> > ar[10];
		char c;
		int r;
		for(int i=0;i<n;i++){
			scanf("%c",&c);
			int win=0,lose=0;
			for(int j=0;j<n-1;j++){
				scanf(" %d",&r);
				if(r==0) win++;
				if(r==1) lose++;
			}
			ar[i]=MP(MP(-win,lose),MP(i,c));
			scanf("\n");
		}
		sort(ar,ar+n);
		for(int i=0;i<n;i++){
			printf("%c\n",ar[i].second.second);
		}
	}
}