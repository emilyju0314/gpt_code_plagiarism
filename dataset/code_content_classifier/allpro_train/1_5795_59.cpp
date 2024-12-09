#include <bits/stdc++.h>
using namespace std;

signed
main(){
		int n;
		while(cin >> n and n!=0)
		{
				vector<string> s(n);
				for(int i=0;i<n;i++)
						cin >> s[i];

				for(int i=0;i<n;i++)
				{
						for(int j=s[i].size()-1;j>=0;j--)
						{
								if(s[i][j]=='.')
								{
										s[i][j] = '+';
										break;
								}
						}
				}
				vector<bool> line(1100,false);

				for(int i=n-1;i>=0;i--)
				{
						for(int j=0;j<s[i].size();j++)
						{
								if(line[j] && s[i][j]=='.')
								{
										s[i][j] = '|';
								}else if(s[i][j]=='+')
								{
										line[j] = true;
										for(int k=j+1;k<line.size();k++)
												line[k] = false;
										break;
								}
						}
				}

				
				for(int i=0;i<n;i++)
				{
						for(int j=s[i].size()-1;j>=0;j--)
						{
								if(s[i][j]=='.')
								{
										s[i][j] = ' ';
								}
						}
				}

				for(int i=0;i<n;i++)
						cout << s[i] << endl;

		}
}
