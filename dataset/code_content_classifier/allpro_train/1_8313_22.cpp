#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 
int main()
{
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	if (h*w%2==0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		if (y%2==1)
		{
			if (x % 2 == 1)
			{
				cout << "Yes" << endl;
			} 
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			if (x % 2 == 1)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}
	}
	
}

