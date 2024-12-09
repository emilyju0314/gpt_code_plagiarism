#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	int answer = count_if(v.begin(), v.end(), [](const int a) {return a % 2 == 0; });
	cout<<answer<<endl;
	return 0;
}

