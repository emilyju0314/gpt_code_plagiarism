#include <bits/stdc++.h>
using namespace std;


typedef __uint128_t Hash;
template<class T>

class RollingHash{
public:
	T src;
	vector<Hash> harr,p;
	
	vector<int> suffixArray;
	RollingHash(T src,Hash w=8999):src(src){
		p.resize(src.size()+1);
		Hash sum = 0;
		for(int i = 0 ; i < src.size() ; i++){
			sum = sum * w + src[i];
			//sum %= mod;
			harr.push_back(sum);
		}
		p[0] = 1;
		for(int i = 1 ; i < p.size() ; i++){
			p[i] = p[i-1] * w;
			//p[i] %= mod;
		}
	}
	// [l,r)
	Hash sub(int l,int r) const{
		if( l >= r ) return 0;
		return harr[r-1] - (l?harr[l-1] * p[r-l]:0);
	}
};

int main(){
	string S,T;
	cin >> S >> T;
	RollingHash<string> s(S),t(T);
	int ans = 0;
	for(int i = 0 ; i+T.size() <= S.size() ; i++){
		int l = 0, r = T.size();
		if( s.sub(i,i+r) == t.sub(0,r) ) continue;
		
		while( l != r ){
			int m = (l+r+1)/2;
			if( s.sub(i,i+m) == t.sub(0,m) ){
				l = m;
			}else{
				r = m-1;
			}
		}
		// cout << l+1 << " " << i+T.size() << ") [" << i << "," << l << ")" << endl;
		if( s.sub(i,i+l) == t.sub(0,l) && s.sub(i+l+1,i+T.size()) == t.sub(l+1,T.size()) ) ans++;
	}
	cout << ans << endl;
}