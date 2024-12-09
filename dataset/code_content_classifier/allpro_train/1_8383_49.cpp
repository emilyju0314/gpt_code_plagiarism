#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	string s;
	int K;
	string tmp;
	map<string,bool> m;
	
	cin >> s >> K;
	
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<s.size()-i+1;j++)
		{
			tmp="";
			for(int k=0;k<i;k++)
				tmp+=s[j+k];
			m.insert({tmp,false});
		}
	}
	
	auto itr=m.begin();
	for(int i=0;i<K-1;i++)++itr;
	
	cout << itr->first << endl;
	return 0;
}
