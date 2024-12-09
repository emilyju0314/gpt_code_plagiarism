#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n;

int main(){
	while(cin>>n){
		int ans=0;
		for(int i=0;i<n;i++)ans+=pow(3,i/2);
		cout<<ans<<endl;
	}
}