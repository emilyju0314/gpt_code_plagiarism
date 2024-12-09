#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int r1[101010], r2[101010];
int main()
{
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++)r1[i + 1] = r1[i] + (s[i] - 'A' + 1);
	for (int i = 0; i < t.size(); i++)r2[i + 1] = r2[i] + (t[i] - 'A' + 1);
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		if ((r1[zb] - r1[za - 1]) % 3 == (r2[zd] - r2[zc - 1]) % 3)printf("YES\n");
		else printf("NO\n");
	}
}