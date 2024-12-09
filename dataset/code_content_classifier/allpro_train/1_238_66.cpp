#include <iostream>
#include <map>
using namespace std;

typedef pair<int,int> P;

int main(){
	int h[6],w[6];
	map<P,int> mp;
	map<int,int> mpp;
	for(int i = 0;i < 6;i++){
		cin >> h[i] >> w[i];
		if(h[i] > w[i]) swap(h[i],w[i]);
		mp[P(h[i],w[i])]++;
		mpp[h[i]]++;
		mpp[w[i]]++;
	}
	bool flag = true;
	if(mp.size() >= 4) flag = false;
	if(mpp.size() >= 4) flag = false;
	if(mpp.size() == 2){
		int same = 0;
		for(int i = 0;i < 6;i++){
			if(w[i] == h[i]) same++;
		}
		if(same != 2) flag = false;
		if(mp.size() != 2) flag = false;
	}else if(mpp.size() == 3){
		if(mp.size() != 3) flag = false;
		for(auto it = mp.begin();it != mp.end();it++){
			if(it->first.first == it->first.second) flag = false;
			if(it->second != 2) flag = false;
		}
	}
	if(flag) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}