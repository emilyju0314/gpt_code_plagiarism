#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int q,t,f,cnt=0; 
char c;
int main()
{
	cin>>s;
	cin>>q;
	while(q--)
	{
		cin>>t;
		if(t==1) cnt++;
		else
		{
			cin>>f>>c;
			if(cnt%2==0)
			{
				if(f==1) s.insert(s.begin(),c);
				else s.insert(s.end(),c);
			}
			else
			{
				if(f==1) s.insert(s.end(),c);
				else s.insert(s.begin(),c);
			}
		}
	}
	if(cnt%2!=0) reverse(s.begin(),s.end());
	cout<<s<<endl;
	return 0;
}