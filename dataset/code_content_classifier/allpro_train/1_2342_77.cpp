#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{   
	string b;
  	getline(cin,b);
  	for(int i=0;i<b.size();i++)
  	{
  		if(b[i]>=97)b[i]=toupper(b[i]);
  		else b[i]=tolower(b[i]);
  		
	  }
	  
	  
	cout<<b<<endl;

	return 0;
}
