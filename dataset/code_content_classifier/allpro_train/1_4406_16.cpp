#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

int main(){
	string red,green,down,out;
	
	while(cin>>red){
		if(red=="-")break;
		cin>>green>>down;
		
		out.clear();
		int ri=0,gi=1,di=0;
		char mid=green[0];
		int c=1;
		
		while(green.size()+red.size()>out.size()+down.size()){
			if(mid==down[di]){
				++di;
				mid=red[ri];
				++ri;
			}else{
				out.push_back(mid);
				mid=green[gi];
				++gi;
			}
		}
		cout<<out<<endl;
	}
}