#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
	int n,r;
	while(scanf(" %d ",&n)!=EOF){
		scanf("%d",&r);
		vector<int> args;
		for(int x=0;x<r;++x){	
			int j;scanf("%d",&j);
			args.push_back(j);
		}
		vector<int> deck;
		for(int x=0;x<n;++x)deck.push_back(x);
		
		queue<int> A,B;
		for(int w=0;w<args.size();++w){
			int i = n-(n+1)/2;
			for(int x=0;x<i;++x)B.push(deck[x]);
			for(int x=i;x<n;++x)A.push(deck[x]);
			i = args[w];
			deck.clear();
			while(A.size()>=i && B.size()>=i){
				for(int x=0;x<i;++x){
					deck.push_back(A.front());
					A.pop();
				}
				for(int x=0;x<i;++x){
					deck.push_back(B.front());
					B.pop();
				}
			}
			while(!A.empty()){
				deck.push_back(A.front());
				A.pop();
			}
			while(!B.empty()){
				deck.push_back(B.front());
				B.pop();
			}
		}
		cout<<deck[n-1]<<endl;
	}
	return 0;
}