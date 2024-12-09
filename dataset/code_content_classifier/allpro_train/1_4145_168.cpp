//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
char chr[128];
char K[128];
int main() {
	cin>>N;
	cin>>chr;
	int chrlen=strlen(chr);
	int ans=0;
	for(int i=0;i<N;i++){
		cin>>K;
		int Klen=strlen(K);
		for(int j=0;j<Klen;j++){
			for(int k=1;j+(chrlen-1)*k<Klen;k++){
				for(int l=0;l<chrlen;l++){
					if(K[j+l*k]!=chr[l]){
						goto fail;
					}
				}
				ans++;
				goto naxtk;
			  fail:;
			}
		}
	  naxtk:;
	}
	cout<<ans<<endl;
	return 0;
}