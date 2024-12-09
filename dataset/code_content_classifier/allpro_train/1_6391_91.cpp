// 2011/04/03 Tazoe

#include <iostream>
#include <string>
using namespace std;

int main()
{
	while(true){
		string str;
		cin >> str;
		if(cin.eof())
			break;

		int num[10];
		for(int i=0; i<10; i++)
			num[i] = str[i]-'0';

		for(int i=9; i>=1; i--)
			for(int j=0; j<i; j++)
				num[j] = (num[j]+num[j+1])%10;

		cout << num[0] << endl;
	}

	return 0;
}