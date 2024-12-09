#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;
 
const static int tx[] = {0,1,1,1,0,-1,-1,-1};
const static int ty[] = {-1,-1,0,1,1,1,0,-1};
 
static const double EPS = 1e-12;

int main(){
  string ref,target;
  while(cin >> ref >> target){
    
    set<string> visited;
    bool isok = false;
    for(int l=0;l<ref.size();l++){
      for(int r=l;r<ref.size();r++){
	const string str = ref.substr(l,r-l+1);
	if(str.size() != target.size()) continue;

	bool tmp_isok = true;
	for(int i=0;i<target.size();i++){
	  if(target[i] == '_') continue;
	  if(str[i] != target[i]){
	    tmp_isok = false;
	  }
	}

	if(tmp_isok){
	  isok = true;
	  goto found;
	}
      }
    }
  found:
    printf("%s\n",isok ? "Yes" : "No");
  }
}
