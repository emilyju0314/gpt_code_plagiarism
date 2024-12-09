#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


map<string,bool> MAP;
string line;
int ans = 0;

void recursive(string tmp){

	if(tmp.length() == 1)return;

	auto at = MAP.find(tmp);
	if(at != MAP.end())return;

	string left = tmp.substr(0,tmp.size()/2);
	string right = tmp.substr(tmp.size()/2);

	if(left == right){
		recursive(left);
	}else{
		MAP[tmp] = true;
		ans++;
		recursive(left);
		recursive(right);
	}
}

int main(){

	int N;
	scanf("%d",&N);
	getchar();
	getline(cin,line);

	recursive(line);

	printf("%d\n",ans);
}