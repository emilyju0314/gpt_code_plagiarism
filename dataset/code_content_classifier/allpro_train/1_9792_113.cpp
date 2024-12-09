#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef pair<string,int> mypair;
int main(){
	map<string,int> mp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		if(q){
			string s;
			cin>>s;
		auto it = mp.find(s);
		if(it!=mp.end())		cout<<it->second<<endl;
		}else{
		string s;
		int x;
		cin>>s>>x;
		mp.erase(s);
		mp.insert(mypair(s,x));
		//mp.insert_or_assign(mypair(s,x));
		}

	}


	return 0;
}

