#include <stdio.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) cerr << #x << "=" << static_cast<bitset<16> >(x) << endl;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 100000000;
typedef double D;
const D EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
using namespace std;
typedef pair<int, int> II;


/** Problem0242 : Input Candidates
 なぜかWrongAnswer **/
 typedef pair<int, string> PP;

bool cmp(const PP &a, const PP &b){
	if(a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main()
{
	int N;
	while (cin>>N, N) {
		map<string, int> list;
		string s;
		cin.ignore();
		rep(k, N) {
			getline(cin, s);

			stringstream ss(s);
			while (!ss.eof()) {
				string tmp; ss>>tmp;
				list[tmp]++;
			}
		}
		vector<PP> v;
		map<string, int>::iterator it = list.begin();
		for (; it!=list.end(); it++) {
			v.push_back(PP(it->second, it->first));
		}
		sort(v.begin(), v.end(), cmp);
		
		vector<PP>::iterator it2 = v.begin();
	
		char c; cin>>c;
		bool first=true;
	
		int num=0;
		for(;it2!=v.end(); it2++) {
			if (num>=5) break;
			if (it2->second[0]==c) {
				if (num>0) cout << " ";
				cout << it2->second;
				num++;
			}
		}
		if (num==0) cout << "NA";
		cout << endl;
	}
}