#include <iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;



int main()
{
	int  u[26] = {};
	char ch;
	while (cin >> ch){
		ch = tolower(ch);
		if (isalpha(ch)){
			u[ch-'a']++ ;
		}
	}
	for (int i = 0; i < 26; i++){
		printf("%c : %d\n", i + 'a', u[i]);
	}
	return 0;
}


