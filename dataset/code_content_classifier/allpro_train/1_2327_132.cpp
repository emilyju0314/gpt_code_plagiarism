// 2011/08/16 Tazoe

#include <iostream>
#include <string>
using namespace std;

int main()
{
	while(true){
		string srv;
		cin >> srv;
		if(srv=="0")		// ツ閉カツ篠堋療ア
			break;

		int ptA = 0;
		int ptB = 0;
		for(int i=1; i<srv.size(); i++)
			if(srv[i]=='A')
				ptA++;
			else
				ptB++;

		if(ptA>ptB)
			ptA++;
		else
			ptB++;

		cout << ptA << ' ' << ptB << endl;
	}

	return 0;
}