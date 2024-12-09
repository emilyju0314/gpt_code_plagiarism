#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


bool operator<(const vector<int>&l, const vector<int>&r) {
	for (int i = 0; i < l.size(); ++i) {
		if(l[i]<r[i])return true;
		else if(l[i]==r[i])continue;
		else return false;
	}
	return false;
}

int main() {
	int N;cin>>N;

	map<vector<int>,int>mp;
	map<int,vector<int>>rev_mp;
	vector<int>v(3);
	iota(v.begin(),v.end(),0);
	{
		for (int i = 0; i < 3; ++i) {
			rotate(v.begin(),v.begin()+1,v.end());
			for (int j = 0; j < 2; ++j) {
				mp[v]=i*2+j;
				rev_mp[i*2+j]=v;
				swap(v[0],v[1]);
			}
		}
	}

	vector<int>nums(6);
	for (int i = 0; i < N; ++i) {
		vector<int>perms(3);
		iota(perms.begin(),perms.end(),0);

		int w;cin>>w;
		for (int j = 0; j < w; ++j) {
			int k;cin>>k;
			swap(perms[k],perms[k+1]);
		}
		nums[mp[perms]]++;
	}

	for (int i = 0; i < 6; ++i) {
		nums[i]=min(3,nums[i]);
	}

	set<pair<int,vector<int>>>memo;
	memo.emplace(mp[vector<int>{0, 1, 2}],nums);

	queue<pair<int,vector<int>>>que;
	que.emplace(mp[vector<int>{0, 1, 2}],nums);

	bool aok=false;
	while (!que.empty()) {
		auto p(que.front());
		que.pop();
		int status_id=p.first;
		vector<int> rest=p.second;

		for (int use_id = 0; use_id < 6; ++use_id) {
			if (rest[use_id]) {
				rest[use_id]--;

				vector<int>now_status(rev_mp[status_id]);
				vector<int>next_status(now_status);
				for (int i = 0; i < 3; ++i) {
					auto next_change(rev_mp[use_id]);

					next_status[next_change[i]]= now_status[i];

				}
				int next_status_id = mp[next_status];
				if(next_status_id==4)aok=true;
				if (memo.find(make_pair(next_status_id, rest)) == memo.end()) {
					memo.emplace(next_status_id, rest);
					que.emplace(next_status_id, rest);
				}

				rest[use_id]++;
			}
		}
	}

	bool ok=memo.find(make_pair(4,vector<int>(6,0)))!=memo.end();
	if(aok)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
