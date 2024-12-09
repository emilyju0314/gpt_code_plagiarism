#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	string s;
	while(cin >> s)
	{
		bool ok = false;
		for(int i = 0; i < 10; ++i)
		{
			vector<string> input;
			string temp;
			for(int j = 0; j < s.size(); ++j)
			{
				if(s[j] == '+' || s[j] == '=')
				{
					input.push_back(temp);
					temp = "";
					continue;
				}
				if(s[j] == 'X')
				{
					temp += '0' + i;
				}
				else
				{
					temp += s[j];
				}
			}
			input.push_back(temp);

			while(input[1].size() > input[0].size())
			{
				input[0]  = "0" + input[0];
			}
			while(input[0].size() > input[1].size())
			{
				input[1]  = "0" + input[1];
			}
			input[0] = "0" + input[0];
			input[1] = "0" + input[1];
			string calcTemp;
			for(int j = input[0].size() - 1; j >= 0; --j)
			{
				int t = (input[0][j] - '0') + (input[1][j] - '0');
				if(t >= 10)
				{
					input[0][j - 1] += 1;
					t -= 10;
				}
				calcTemp += '0' + t;
			}
			reverse(calcTemp.begin(), calcTemp.end());
			string calc;
			if(calcTemp[0] == '0')
			{
				for(int j = 1; j < calcTemp.size(); ++j)
				{
					calc += calcTemp[j];
				}
			}
			else
			{
				calc = calcTemp;
			}
			if(calc == input[2])
			{
				cout << i << endl;
				ok = true;
			}
		}
		if(!ok)
		{
			cout << "NA" << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}