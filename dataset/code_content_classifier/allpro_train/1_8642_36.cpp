#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long a[300000],b[300000],n;
vector<pair<long long,long long> > vec;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>a[i];vec.push_back(make_pair(a[i],i));}
	for(int i=0;i<n;i++){cin>>b[i];vec.push_back(make_pair(b[i],i+n));}
	sort(vec.begin(),vec.end());
	long long v=1;long long cnt=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i].second<n){
			if(cnt<0){v*=1LL*-cnt;}
			cnt++;
		}
		if(vec[i].second>=n){
			if(cnt>0){v*=1LL*cnt;}
			cnt--;
		}
		v%=1000000007LL;
	}
	cout<<v<<endl;
	return 0;
}