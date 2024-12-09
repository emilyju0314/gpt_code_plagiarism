#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

const int maxn=505;

int a[maxn];
bool bio[maxn];
int n;
int m;
pair < int, int > sol;

void upd(int x){
	for(int i=0; i<n; i++){
		if(!bio[i]){
			a[i]-=x;
		}
	}
}

void delaj(){
	int br=3;
	vector < int > v;
	while(br==3){
		br=0;
		for(int i=0; i<n; i++){
			if(!bio[i]){
				if(a[i]==1){
					br++;
				}
			}
		}
		if(br==3){
			m-=3;
			for(int i=0; i<n; i++){
				if(!bio[i]){
					if(a[i]==1){
						bio[i]=1;
						v.push_back(i);
					}
					else{
						a[i]-=3;
					}
				}
			}
			sol={v[0], v[1]};
			v.clear();
		}
	}
	br=3;
	while(br==3){
		br=0;
		for(int i=0; i<n; i++){
			if(!bio[i]){
				if(a[i]==m-1){
					br++;
				}
			}
		}
		if(br==3){
			for(int i=0; i<n; i++){
				if(!bio[i]){
					if(a[i]==m-1){
						bio[i]=1;
						v.push_back(i);
					}
				}
			}
			m-=3;
			sol={v[0], v[1]};
			v.clear();
		}
	}
}

vector < int > ind;

bool cmp(int aa, int b){
	return a[aa]<a[b];
}

bool cmp1(array < int, 3 > aa, array < int, 3 > b){
	return aa[0]>b[0];
}

vector < array < int, 3 > > pitaj;

void rijesi(){
	for(int i=0; i<n; i++){
		if(!bio[i]){
			ind.push_back(i);
		}
	}
	sort(ind.begin(), ind.end(), cmp);
	int k=ind.size();
	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			pitaj.push_back({a[ind[j]]-a[ind[i]], ind[j], ind[i]});
		}
	}
	sort(pitaj.begin(), pitaj.end(), cmp1);
	string s;
	for(int i=0; i<(int)pitaj.size(); i++){
		cout << "? " << pitaj[i][1]+1 << ' ' << pitaj[i][2]+1 << '\n';
		cout.flush();
		cin >> s;
		if(s=="Yes"){
			cout << "! " << pitaj[i][1]+1 << ' ' << pitaj[i][2]+1 << '\n';
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int br1, br2;
	bool p=1;
	m=n-1;
	while(p){
		p=0;
		br1=0;
		br2=0;
		for(int i=0; i<n; i++){
			if(!bio[i]){
				if(a[i]==0){
					p=1;
					br1++;
					bio[i]=1;
				}
				else if(a[i]==m){
					p=1;
					br2++;
					bio[i]=1;
				}
			}
		}
		m-=br1+br2;
		upd(br1);
	}
	if(m==-1){
		cout << "! 0 0\n";
		return 0; 
	}
	delaj();
	if(m==-1){
		cout << "! " << sol.first+1 << ' ' << sol.second+1 << '\n';
		return 0;
	}
	rijesi();
	return 0;
}