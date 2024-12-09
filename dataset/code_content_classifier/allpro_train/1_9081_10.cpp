#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int n,i,r,last,time,day;
	for(;cin>>n,n;){
		vector<pair<int,string> >program;
		set<string>precious;
		{
			string s;
			map<string,int>m;
			for(;n--;){
				cin>>s>>day>>time;
				program.push_back(make_pair(day*1440+time/100*60+time%100,s));
				m[s]=day*1440+time/100*60+time%100;
			}
			bool flg=true;
			for(cin>>n;n--;){
				cin>>s;
				set<string>::iterator it=precious.begin();
				for(;it!=precious.end();it++){
					if(abs(m[*it]-m[s])<30)flg=false;
				}
				precious.insert(s);
			}
			if(!flg){puts("-1");continue;}
		}
		sort(program.begin(),program.end());
		for(last=r=i=0;i<program.size();i++){
			if(program[i].first>=last){
				last=program[i].first+30;
				r++;
			}else if(precious.find(program[i].second)!=precious.end()){
				last=program[i].first+30;
			}
		}
		printf("%d\n",r);
		next:;
	}
}