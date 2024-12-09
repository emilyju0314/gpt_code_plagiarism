#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	int a = (int)s.size();
	int b = (int)t.size();
	if(s==t){
		int x=0;
		while(x!=n){
			cout << s;
			x += a;
		}
		cout << endl;
		return 0;
	}
	if(s<t){
		if(a<b){
			int x = a;
			string tmp = s;
			while(x<b){
				tmp += s;
				x+=a;
			}
			string tmp2 = t;
			if(x>b){
				tmp2 += t;
			}
			if(tmp>tmp2){
				swap(s,t);
				swap(a,b);	
			}
		}
	}
	if(s>t){
		if(a<=b){
			swap(s,t);
			swap(a,b);
		}else{
			int x = b;
			string tmp = t;
			while(x<a){
				tmp += t;
				x+=b;
			}
			string tmp2 = s;
			if(x>a){
				tmp2 += s;
			}
			if(tmp2>tmp){
				swap(s,t);
				swap(a,b);	
			}
		}
	}
	int x = 0;
	int k = 0;
	for(int i=0;i<2000000;i++){
		if(x>n)break;
		if((n-x)%b==0){
			k = i;
		}
		x += a;
	}
	for(int i=0;i<k;i++){
		cout << s;
	}
	x = a*k;
	while(x!=n){
		cout << t;
		x+=b;
	}
	cout << endl;
	return 0;
}